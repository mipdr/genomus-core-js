print("Precompilation time, ou yeah;")

code = open('src/sample.cpp', 'w')

code.write("""/*
#################################################################################
###########        Automatically-generated file.  Do not edit!        ###########
#################################################################################
*/""")

code.write('\n\n// Saludos desde tiempo pre-compilación! 😎😎')

code.close()