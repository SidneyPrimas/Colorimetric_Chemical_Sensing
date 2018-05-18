To Do: 
+ Single C File: Write a single C file that: 1) Collects data from the virtual com port, 2) processes the data and 3) outputs it into a file that is easily reasable by python (or runs a python script directly)
++ Directly call python script to visualize data. 
+ Sanity Checking on UART: Ensure that the UART transmission is only read at the beginning of a transmissin (and doesn't get corrupted by starting at an intermmediate point)
+ Create ADC infrastructure: Options for configuring the ADC, function to extrac bits from ADC ouput (including polarity, data, ranging info) and function to catch error in data. 
+ Error LED: Use an LED to output a significant error when it happens. 
+ Data collection Control: Use a button to collect data from ADC and print it out to the terminal  
+ Review the UART implementation 