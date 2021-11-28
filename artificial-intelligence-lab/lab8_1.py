import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
import matplotlib.pyplot as plt

market_value =  ctrl.Antecedent(np.arange(0, 101, 1), 'market_value')
location =  ctrl.Antecedent(np.arange(0, 11, 0.5), 'location')
house = ctrl.Consequent(np.arange(0, 11, 1), 'house')

market_value['low'] = fuzz.trapmf(market_value.universe, [0, 0, 5, 10])
market_value['medium'] = fuzz.trapmf(market_value.universe, [5, 10, 18, 25])
market_value['high'] = fuzz.trapmf(market_value.universe, [20, 25, 65, 85])
market_value['very_high'] = fuzz.trapmf(market_value.universe, [65, 85, 100, 100])

location['bad'] = fuzz.trapmf(location.universe, [0, 0, 1.5, 4])
location['fair'] = fuzz.trapmf(location.universe, [2.5, 5, 6, 8.5])
location['excellent'] = fuzz.trapmf(location.universe, [6, 8.5, 10, 10])

house['very_low'] = fuzz.trimf(house.universe, [0, 0, 3])
house['low'] = fuzz.trimf(house.universe, [0, 3, 6])
house['medium'] = fuzz.trimf(house.universe, [2, 5, 8])
house['high'] = fuzz.trimf(house.universe, [4, 7, 10])
house['very_high'] = fuzz.trimf(house.universe, [7, 10, 10])

market_value.view()

location.view()

house.view()

he_rule1 = ctrl.Rule(market_value['low'], house['low'])
he_rule2 = ctrl.Rule(location['bad'], house['low'])

he_rule3 = ctrl.Rule(market_value['low'] & location['bad'], house['very_low'])
he_rule4 = ctrl.Rule(market_value['medium'] & location['bad'], house['low'])
he_rule5 = ctrl.Rule(market_value['high'] & location['bad'], house['medium'])
he_rule6 = ctrl.Rule(market_value['very_high'] & location['bad'], house['high'])

he_rule7 = ctrl.Rule(market_value['low'] & location['fair'], house['low'])
he_rule8 = ctrl.Rule(market_value['medium'] & location['fair'], house['medium'])
he_rule9 = ctrl.Rule(market_value['high'] & location['fair'], house['high'])
he_rule10 = ctrl.Rule(market_value['very_high'] & location['fair'], house['very_high'])

he_rule11 = ctrl.Rule(market_value['low'] & location['excellent'], house['medium'])
he_rule12 = ctrl.Rule(market_value['medium'] & location['excellent'], house['high'])
he_rule13 = ctrl.Rule(market_value['high'] & location['excellent'], house['very_high'])
he_rule14 = ctrl.Rule(market_value['very_high'] & location['excellent'], house['very_high'])

he_Rules = [he_rule1, he_rule2, he_rule3, he_rule4, he_rule5, he_rule6, he_rule7, he_rule8, he_rule9, he_rule10, he_rule11, he_rule12, he_rule13, he_rule14]
house_ctrl = ctrl.ControlSystem(he_Rules)
house_eval = ctrl.ControlSystemSimulation(house_ctrl)

assets =  ctrl.Antecedent(np.arange(0, 1001, 1), 'assets')
income =  ctrl.Antecedent(np.arange(0, 101, 1), 'income')
applicant = ctrl.Consequent(np.arange(0, 11, 1), 'applicant')

assets['low'] = fuzz.trimf(assets.universe, [0, 0, 150])
assets['medium'] = fuzz.trapmf(assets.universe, [50, 250, 450, 650])
assets['high'] = fuzz.trapmf(assets.universe, [500, 700, 1000, 1000])

income['low'] = fuzz.trapmf(income.universe, [0, 0, 10, 25])
income['medium'] = fuzz.trimf(income.universe, [15, 35, 55])
income['high'] = fuzz.trimf(income.universe, [40, 60, 80])
income['very_high'] = fuzz.trapmf(income.universe, [60, 80, 100, 100])

applicant['low'] = fuzz.trapmf(applicant.universe, [0, 0, 2, 4])
applicant['medium'] = fuzz.trimf(applicant.universe, [2, 5, 8])
applicant['high'] = fuzz.trapmf(applicant.universe, [6, 8, 10, 10])

assets.view()

income.view()

applicant.view()

ae_rule1 = ctrl.Rule(assets['low'] & income['low'], applicant['low'])
ae_rule2 = ctrl.Rule(assets['low'] & income['medium'], applicant['low'])
ae_rule3 = ctrl.Rule(assets['low'] & income['high'], applicant['medium'])
ae_rule4 = ctrl.Rule(assets['low'] & income['very_high'], applicant['high'])

ae_rule5 = ctrl.Rule(assets['medium'] & income['low'], applicant['low'])
ae_rule6 = ctrl.Rule(assets['medium'] & income['medium'], applicant['medium'])
ae_rule7 = ctrl.Rule(assets['medium'] & income['high'], applicant['high'])
ae_rule8 = ctrl.Rule(assets['medium'] & income['very_high'], applicant['high'])

ae_rule9 = ctrl.Rule(assets['high'] & income['low'], applicant['medium'])
ae_rule10 = ctrl.Rule(assets['high'] & income['medium'], applicant['medium'])
ae_rule11 = ctrl.Rule(assets['high'] & income['high'], applicant['high'])
ae_rule12 = ctrl.Rule(assets['high'] & income['very_high'], applicant['high'])

ae_Rules = [ae_rule1, ae_rule2, ae_rule3, ae_rule4, ae_rule5, ae_rule6, ae_rule7, ae_rule8, ae_rule9, ae_rule10, ae_rule11, ae_rule12]
applicant_ctrl = ctrl.ControlSystem(ae_Rules)
applicant_eval = ctrl.ControlSystemSimulation(applicant_ctrl)

income =  ctrl.Antecedent(np.arange(0, 101, 1), 'income')
interest =  ctrl.Antecedent(np.arange(0, 11, 0.5), 'interest')
applicant = ctrl.Antecedent(np.arange(0, 11, 1), 'applicant')
house = ctrl.Antecedent(np.arange(0, 11, 1), 'house')
credit = ctrl.Consequent(np.arange(0, 11, 1), 'credit')

income['low'] = fuzz.trapmf(income.universe, [0, 0, 10, 25])
income['medium'] = fuzz.trimf(income.universe, [15, 35, 55])
income['high'] = fuzz.trimf(income.universe, [40, 60, 80])
income['very_high'] = fuzz.trapmf(income.universe, [60, 80, 100, 100])

interest['low'] = fuzz.trapmf(interest.universe, [0, 0, 2, 5])
interest['medium'] = fuzz.trapmf(interest.universe, [2, 4, 6, 8])
interest['high'] = fuzz.trapmf(interest.universe, [6, 8.5, 10, 10])

applicant['low'] = fuzz.trapmf(applicant.universe, [0, 0, 2, 4])
applicant['medium'] = fuzz.trimf(applicant.universe, [2, 5, 8])
applicant['high'] = fuzz.trapmf(applicant.universe, [6, 8, 10, 10])

house['very_low'] = fuzz.trimf(house.universe, [0, 0, 3])
house['low'] = fuzz.trimf(house.universe, [0, 3, 6])
house['medium'] = fuzz.trimf(house.universe, [2, 5, 8])
house['high'] = fuzz.trimf(house.universe, [4, 7, 10])
house['very_high'] = fuzz.trimf(house.universe, [7, 10, 10])

credit['very_low'] = fuzz.trimf(credit.universe, [0, 0, 3])
credit['low'] = fuzz.trimf(credit.universe, [0, 3, 6])
credit['medium'] = fuzz.trimf(credit.universe, [2, 5, 8])
credit['high'] = fuzz.trimf(credit.universe, [4, 7, 10])
credit['very_high'] = fuzz.trimf(credit.universe, [7, 10, 10])

income.view()

interest.view()

applicant.view()

house.view()

credit.view()

ce_rule1 = ctrl.Rule(income['low'] & interest['medium'], credit['very_low'])
ce_rule2 = ctrl.Rule(income['low'] & interest['high'], credit['very_low'])
ce_rule3 = ctrl.Rule(income['medium'] & interest['high'], credit['low'])
ce_rule4 = ctrl.Rule(applicant['low'], credit['very_low'])
ce_rule5 = ctrl.Rule(house['very_low'], credit['very_low'])

ce_rule6 = ctrl.Rule(applicant['medium'] & house['very_low'], credit['low'])
ce_rule7 = ctrl.Rule(applicant['medium'] & house['low'], credit['low'])
ce_rule8 = ctrl.Rule(applicant['medium'] & house['medium'], credit['medium'])
ce_rule9 = ctrl.Rule(applicant['medium'] & house['high'], credit['high'])
ce_rule10 = ctrl.Rule(applicant['medium'] & house['very_high'], credit['high'])

ce_rule11 = ctrl.Rule(applicant['high'] & house['very_low'], credit['low'])
ce_rule12 = ctrl.Rule(applicant['high'] & house['low'], credit['medium'])
ce_rule13 = ctrl.Rule(applicant['high'] & house['medium'], credit['high'])
ce_rule14 = ctrl.Rule(applicant['high'] & house['high'], credit['high'])
ce_rule15 = ctrl.Rule(applicant['high'] & house['very_high'], credit['very_high'])

ce_Rules = [ce_rule1, ce_rule2, ce_rule3, ce_rule4, ce_rule5, ce_rule6, ce_rule7, ce_rule8, ce_rule9, ce_rule10, ce_rule11, ce_rule12, ce_rule13, ce_rule14, ce_rule15]
credit_ctrl = ctrl.ControlSystem(ce_Rules)
credit_eval = ctrl.ControlSystemSimulation(credit_ctrl)

house_eval.input['market_value'] = 60      # 0 to 100
house_eval.input['location'] = 7           # 0 to 10
applicant_eval.input['assets'] = 400       # 0 to 1000
applicant_eval.input['income'] = 70        # 0 to 100

house_eval.compute()
applicant_eval.compute()

credit_eval.input['income'] = 70           # 0 to 100
credit_eval.input['interest'] = 7          # 0 to 10
credit_eval.input['applicant'] = applicant_eval.output['applicant']
credit_eval.input['house'] = house_eval.output['house']

credit_eval.compute()
credit_eval.output['credit']

credit.view(sim=credit_eval)

plt.show()
