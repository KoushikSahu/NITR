import numpy as np
from sompy.sompy import SOMFactory
import pandas as pd
import glob
import os


if __name__ == '__main__':
    df = pd.read_csv('./en_climate_summaries_All_03-2022.csv')

    data = df[['Lat', 'Long', 'Tm', 'Tx', 'Tn', 'P']]
    data = data.apply(pd.to_numeric,  errors='coerce')
    data = data.dropna(how='any')
    names = ['Latitude', "longitude", 'Monthly Median temperature (C)','Monthly Max temperature (C)', 'Monthly Min temperature (C)', 'Monthly total precipitation (mm)']

    print(data.head())

    sm = SOMFactory().build(data.values, normalization = 'var', initialization='pca', component_names=names)
    sm.train(n_job=1, verbose=False, train_rough_len=2, train_finetune_len=5)

    topographic_error = sm.calculate_topographic_error()
    quantization_error = np.mean(sm._bmu[1])
    print ("Topographic error = %s; Quantization error = %s" % (topographic_error, quantization_error))

    from sompy.visualization.mapview import View2D
    view2D  = View2D(10,10,"rand data",text_size=12)
    view2D.show(sm, col_sz=4, which_dim="all", desnormalize=True)

    from sompy.visualization.umatrix import UMatrixView

    umat  = UMatrixView(width=10,height=10,title='U-matrix')
    umat.show(sm)

    from sompy.visualization.hitmap import HitMapView
    K = 20 
    K_opt = 18 
    [labels, km, norm_data] = sm.cluster(K,K_opt)
    hits  = HitMapView(20,20,"Clustering",text_size=12)
    a=hits.show(sm)

    import gmplot

    gmap = gmplot.GoogleMapPlotter(54.2, -124.875224, 6)
    j = 0
    for i in km.cluster_centers_:
        gmap.marker(i[0],i[1],'red', title="Centroid " + str(j))
        j += 1

    gmap.draw("centroids_map.html")


    from bs4 import BeautifulSoup

    def insertapikey(fname, apikey):
        """put the google api key in a html file"""
        def putkey(htmltxt, apikey, apistring=None):
            """put the apikey in the htmltxt and return soup"""
            if not apistring:
                apistring = "https://maps.googleapis.com/maps/api/js?key=%s&callback=initMap"
            soup = BeautifulSoup(htmltxt, 'html.parser')
            body = soup.body
            src = apistring % (apikey, )
            tscript = soup.new_tag("script", src=src)
            body.insert(-1, tscript)
            return soup
        htmltxt = open(fname, 'r').read()
        soup = putkey(htmltxt, apikey)
        newtxt = soup.prettify()
        open(fname, 'w').write(newtxt)
    API_KEY= 'YOUR API KEY HERE'
    insertapikey("centroids_map.html", API_KEY)


    gmap = gmplot.GoogleMapPlotter(54.2, -124.875224, 6)
    j = 0
    for i in km.cluster_centers_:
        gmap.marker(i[0],i[1],'red', title="Centroid " + str(j))
        j += 1

    gmap.draw("centroids_map.html")
