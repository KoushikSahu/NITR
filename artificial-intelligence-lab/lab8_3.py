import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
import matplotlib.pyplot as plt

her_2 =  ctrl.Antecedent(np.arange(0, 101, 1), 'her_2')
hormone_receptors =  ctrl.Antecedent(np.arange(0, 11, 0.5), 'hormone_receptors')
risk_age =  ctrl.Antecedent(np.arange(0, 11, 0.5), 'risk_age')
grade = ctrl.Antecedent(np.arange(0, 11, 1), 'grade')
tumor_size = ctrl.Antecedent(np.arange(0, 11, 1), 'tumor_size')
lymph_node = ctrl.Antecedent(np.arange(0, 11, 1), 'lymph_node')

risk_status = ctrl.Consequent(np.arange(0, 11, 1), 'risk_status')

her_2['negative'] = fuzz.trapmf(her_2.universe, [0, 0, 5, 10])
her_2['positive'] = fuzz.trapmf(her_2.universe, [1, 2, 8, 15])

hormone_receptors['weak_positive'] = fuzz.trapmf(hormone_receptors.universe, [5, 10, 18, 25])
hormone_receptors['moderate_positive'] = fuzz.trapmf(hormone_receptors.universe, [7, 19, 21, 40])

risk_age['high'] = fuzz.trapmf(risk_age.universe, [20, 25, 65, 85])
risk_age['very_high'] = fuzz.trapmf(risk_age.universe, [10, 15, 25, 45])
risk_age['low'] = fuzz.trapmf(risk_age.universe, [11,19,20,22])

grade['grade1'] = fuzz.trapmf(grade.universe, [65, 85, 100, 100])
grade['grade2'] = fuzz.trapmf(grade.universe, [35, 55, 70, 70])
grade['grade3'] = fuzz.trapmf(grade.universe, [12, 20, 60, 80])

tumor_size['small'] = fuzz.trapmf(tumor_size.universe, [0, 0, 1.5, 4])
tumor_size['intermediate'] = fuzz.trapmf(tumor_size.universe, [0, 1.5, 4, 6.5])

lymph_node['zero'] = fuzz.trapmf(lymph_node.universe, [2.5, 5, 6, 8.5])
lymph_node['intermediate_num'] = fuzz.trapmf(lymph_node.universe, [3.5, 6, 8, 8.5])
lymph_node['high_num'] = fuzz.trapmf(lymph_node.universe, [9.5, 20, 35, 40.5])

risk_status['low'] = fuzz.trimf(risk_status.universe, [0, 0, 3])
risk_status['intermediate'] = fuzz.trimf(risk_status.universe, [0, 3, 6])
risk_status['high'] = fuzz.trimf(risk_status.universe, [2, 5, 8])

her_2.view()

hormone_receptors.view()

risk_age.view()

grade.view()

tumor_size.view()

lymph_node.view()

risk_status.view()

bc_rule1 = ctrl.Rule(lymph_node['high_num'],risk_status['high'])
bc_rule2 = ctrl.Rule(lymph_node['intermediate_num'],her_2['positive'],risk_status['high'])
bc_rule3 = ctrl.Rule(lymph_node['intermediate_num'],her_2['negative'],risk_status['intermediate'])
bc_rule4 = ctrl.Rule(her_2['positive'],risk_status['intermediate'])
bc_rule5 = ctrl.Rule(risk_age['very_high'],risk_status['intermediate'])
bc_rule6 = ctrl.Rule(tumor_size['intermediate'],risk_status['intermediate'])
bc_rule7 = ctrl.Rule(grade['grade3'],risk_status['intermediate'])
bc_rule8 = ctrl.Rule(grade['grade3'],risk_status['intermediate'])
bc_rule9 = ctrl.Rule(grade['grade1'],her_2['negative'],lymph_node['zero'],risk_status['low'])

bc_Rules = [bc_rule1, bc_rule2, bc_rule1, bc_rule4, bc_rule5, bc_rule6, bc_rule7, bc_rule8, bc_rule9]
Cancer_ctrl = ctrl.ControlSystem(bc_Rules)
cancer_eval = ctrl.ControlSystemSimulation(Cancer_ctrl)

plt.show()
