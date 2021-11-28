from simpful import *
FS = FuzzySystem()

S_1 = FuzzySet(points=[[0., 1.],[50000,1],  [100000., 0.]], term="low")
S_2 = FuzzySet(points=[[50000., 0.], [100000., 1.],[200000., 1.], [250000., 0.]], term="medium")
S_3 = FuzzySet(points=[[200000., 0.],[300000,1],[600000,1],  [850000., 0.]], term="high")
S_4 = FuzzySet(points=[[650000., 0.],  [850000., 1.], [1000000,1]], term="very_high")
FS.add_linguistic_variable("MarketValue", LinguisticVariable([S_1, S_2, S_3, S_4], concept="Market-Value"))
FS.plot_variable("MarketValue")

S_1 = FuzzySet(points=[[0., 1.],[1.5,1],  [4., 0.]], term="bad")
S_2 = FuzzySet(points=[[2.5, 0.], [5., 1.],[6., 1.], [8.5, 0.]], term="fair")
S_3 = FuzzySet(points=[[6., 0.],[8.5,1],[10,1]], term="excellent")
FS.add_linguistic_variable("Location", LinguisticVariable([S_1, S_2, S_3], concept="Location"))
FS.plot_variable("Location")

# Define output crisp values
FS.set_crisp_output_value("very_low", 1)
FS.set_crisp_output_value("low", 3)
FS.set_crisp_output_value("medium", 5)
FS.set_crisp_output_value("high", 7)
FS.set_crisp_output_value("very_high", 9)

R1 = "IF (MarketValue IS low) THEN (House IS low)"
R2 = "IF (Location IS bad) THEN (House IS low)"
R3 = "IF (Location IS bad) AND (MarketValue IS low) THEN (House IS very_low)"
R4 = "IF (Location IS bad) AND (MarketValue IS medium) THEN (House IS low)"
R5 = "IF (Location IS bad) AND (MarketValue IS high) THEN (House IS medium)"
R6 = "IF (Location IS bad) AND (MarketValue IS very_high) THEN (House IS high)"
R7 = "IF (Location IS fair) AND (MarketValue IS low) THEN (House IS low)"
R8 = "IF (Location IS fair) AND (MarketValue IS medium) THEN (House IS medium)"
R9 = "IF (Location IS fair) AND (MarketValue IS high) THEN (House IS high)"
R10= "IF (Location IS fair) AND (MarketValue IS very_high) THEN (House IS very_high)"
R11= "IF (Location IS excellent) AND (MarketValue IS low) THEN (House IS medium)" 
R12= "IF (Location IS excellent) AND (MarketValue IS medium) THEN (House IS high)"
R13= "IF (Location IS excellent) AND (MarketValue IS high) THEN (House IS very_high)" 
R14= "IF (Location IS excellent) AND (MarketValue IS very_high) THEN (House IS very_high)"
FS.add_rules([R1, R2, R3, R4, R5, R6, R7, R9, R10, R11, R12, R13, R14, R8])

# Set antecedents values
FS.set_variable("MarketValue", 146000)
FS.set_variable("Location", 7.2)

# Perform Sugeno inference and print output
print(FS.Sugeno_inference(["House"]))

FS2 = FuzzySystem()

# Define fuzzy sets and linguistic variables
S_1 = FuzzySet(points=[[0., 1.],[150000,0]], term="low")
S_2 = FuzzySet(points=[[50000., 0.], [250000., 1.],[450000., 1.], [650000., 0.]], term="medium")
S_3 = FuzzySet(points=[[500000., 0.],[700000,1],[1000000,1]], term="high")
FS2.add_linguistic_variable("Asset", LinguisticVariable([S_1, S_2, S_3], concept="Asset"))
FS2.plot_variable("Asset")

S_1 = FuzzySet(points=[[0., 1.],[12500,1],  [25000., 0.]], term="low")
S_2 = FuzzySet(points=[[15000, 0.], [35000., 1.],[55000., 0.]], term="medium")
S_3 = FuzzySet(points=[[40000., 0.],[60000,1],[80000,0]], term="high")
S_4 = FuzzySet(points=[[60000., 0.],[80000,1],[100000,1]], term="very_high")
FS2.add_linguistic_variable("Income", LinguisticVariable([S_1, S_2, S_3, S_4], concept="Income"))
FS2.plot_variable("Income")

# Define output crisp values
FS2.set_crisp_output_value("low", 1.45)
FS2.set_crisp_output_value("medium", 5)
FS2.set_crisp_output_value("high", 8.55)

R1 = "IF (Asset IS low) AND (Income IS low) THEN (Applicant IS low)"
R2 = "IF (Asset IS low) AND (Income IS medium) THEN (Applicant IS low)"
R3 = "IF (Asset IS low) AND (Income IS high) THEN (Applicant IS medium)"
R4 = "IF (Asset IS low) AND (Income IS very_high) THEN (Applicant IS high)"
R5 = "IF (Asset IS medium) AND (Income IS low) THEN (Applicant IS low)"
R6 = "IF (Asset IS medium) AND (Income IS medium) THEN (Applicant IS medium)"
R7 = "IF (Asset IS medium) AND (Income IS high) THEN (Applicant IS high)"
R8 = "IF (Asset IS medium) AND (Income IS very_high) THEN (Applicant IS high)"
R9 = "IF (Asset IS high) AND (Income IS low) THEN (Applicant IS medium)"
R10= "IF (Asset IS high) AND (Income IS medium) THEN (Applicant IS medium)"
R11= "IF (Asset IS high) AND (Income IS high) THEN (Applicant IS high)" 
R12= "IF (Asset IS high) AND (Income IS very_high) THEN (Applicant IS high)"
FS2.add_rules([R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12])

# Set antecedents values
FS2.set_variable("Asset", 520000)
FS2.set_variable("Income", 60000)

# Perform Sugeno inference and print output
print(FS2.Sugeno_inference(["Applicant"]))

# A simple fuzzy inference system for the tipping problem
# Create a fuzzy system object
FS3 = FuzzySystem()

S_1 = FuzzySet(points=[[0., 1.],[12500,1],  [25000., 0.]], term="low")
S_2 = FuzzySet(points=[[15000, 0.], [35000., 1.],[55000., 0.]], term="medium")
S_3 = FuzzySet(points=[[40000., 0.],[60000,1],[80000,0]], term="high")
S_4 = FuzzySet(points=[[60000., 0.],[80000,1],[100000,1]], term="very_high")
FS3.add_linguistic_variable("Income", LinguisticVariable([S_1, S_2, S_3, S_4], concept="Income"))
FS3.plot_variable("Income")

S_1 = FuzzySet(points=[[0., 1.],[2,1],  [5., 0.]], term="low")
S_2 = FuzzySet(points=[[2, 0.], [4., 1.], [6,1], [8., 0.]], term="medium")
S_3 = FuzzySet(points=[[6., 0.],[8.5,1],[10,1]], term="high")
FS3.add_linguistic_variable("Interest", LinguisticVariable([S_1, S_2, S_3], concept="Interest"))
FS3.plot_variable("Interest")

S_1 = FuzzySet(points=[[0., 1.],[2,1],  [4., 0.]], term="low")
S_2 = FuzzySet(points=[[2, 0.], [5., 1.], [8., 0.]], term="medium")
S_3 = FuzzySet(points=[[6., 0.],[8,1],[10,1]], term="high")
FS3.add_linguistic_variable("Applicant", LinguisticVariable([S_1, S_2, S_3], concept="Applicant"))
FS3.plot_variable("Applicant")

S_1 = FuzzySet(points=[[0., 1.],[3,0]], term="very_low")
S_2 = FuzzySet(points=[[0, 0.], [3., 1.],[6., 0.]], term="low")
S_3 = FuzzySet(points=[[2., 0.],[5,1],[8,0]], term="medium")
S_4 = FuzzySet(points=[[4., 0.],[7,1],[10,0]], term="high")
S_5 = FuzzySet(points=[[7., 0.],[10,1]], term="very_high")
FS3.add_linguistic_variable("House", LinguisticVariable([S_1, S_2, S_3, S_4,S_5], concept="House"))
FS3.plot_variable("House")

# Define output crisp values

FS3.set_crisp_output_value("very_low", 1)
FS3.set_crisp_output_value("low", 3)
FS3.set_crisp_output_value("medium", 5)
FS3.set_crisp_output_value("high", 7)
FS3.set_crisp_output_value("very_high", 9)

R1 = "IF (Income IS low) AND (Interest IS medium) THEN (Credit IS very_low)"
R2 = "IF (Income IS low) AND (Interest IS high) THEN (Credit IS very_low)"
R3 = "IF (Income IS medium) AND (Interest IS high) THEN (Credit IS low)"
R4 = "IF (Applicant IS low) THEN (Credit IS very_low)"
R5 = "IF (House IS very_low) THEN (Credit IS very_low)"
R6 = "IF (Applicant IS medium) AND (House IS very_low) THEN (Credit IS low)"
R7 = "IF (Applicant IS medium) AND (House IS low) THEN (Credit IS low)"
R8 = "IF (Applicant IS medium) AND (House IS medium) THEN (Credit IS medium)"
R9 = "IF (Applicant IS medium) AND (House IS high) THEN (Credit IS high)"
R10= "IF (Applicant IS medium) AND (House IS very_high) THEN (Credit IS high)"
R11= "IF (Applicant IS high) AND (House IS very_low) THEN (Credit IS low)" 
R12= "IF (Applicant IS high) AND (House IS low) THEN (Credit IS medium)"
R13= "IF (Applicant IS high) AND (House IS medium) THEN (Credit IS high)" 
R14= "IF (Applicant IS high) AND (House IS high) THEN (Credit IS high)"
R15= "IF (Applicant IS high) AND (House IS very_high) THEN (Credit IS very_high)" 
FS3.add_rules([R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15])

# Set antecedents values
FS3.set_variable("Income", 28500)
FS3.set_variable("Interest", 2.8)
FS3.set_variable("Applicant", 5.2)
FS3.set_variable("House", 2.4)

# Perform Sugeno inference and print output
print(FS3.Sugeno_inference(["Credit"]))

