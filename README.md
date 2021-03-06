# Chemical Biosensor for Urine

The goal of the system is to passively detect biomarkers in urine while the patient is using the bathroom. Biomarkers (including glucose, proteins, bacteria) can be detected in urine using a dipstick assay. The output of this dipstick is a color. In this project, we built a system to perform a disptick urine assay, and then  measure the concentration of the target particles through the color curve of the assay. The system uses RGB LEDs and photodiodes to monitor the color curve, and estimate the particle concentration.  

We implemented the system on the [nRF51](http://infocenter.nordicsemi.com/pdf/nRF51822_PS_v3.1.pdf). And, for an ADC, we implemented the [LTC2492](http://www.analog.com/media/en/technical-documentation/data-sheets/2492fe.pdf). To offload raw data, we used a UART protocol. 
  
In this repo, we only included the C code for the processor, and not the offline scripts used to process the collected data. 

**Acknowledgments:** This project was part of my initial research at MIT with [Professor Charlie Sodini](http://imes.mit.edu/people/faculty/sodini-charles/), which then evolved into the [AutoScope](https://github.com/SidneyPrimas/AutoScope). For parts of the project, Jeffry Wicaksana helped out as well. 
  
**Project Status**: W built a proof-of-concept for the system. Specifcally, we built a physical prototype to process solutions (not urine yet). And, we demonstrated the ability of the colorimetric sensing system to estimate concentration from the color curve (not with urine). More work is needed to demonstrate the functionality of the system with urine, and to further characterize the system. 

## Some Images
Here are a few images to help visualize the system. 
<div>
  <div>
    <img src="https://github.com/SidneyPrimas/Colorimetric_Chemical_Sensing/blob/master/diagram_device.png" alt="CoverImage1" style="width:100%" width="200">
  </div>
  <div>
    <img src="https://github.com/SidneyPrimas/Colorimetric_Chemical_Sensing/blob/master/diagram_capsule.png" alt="CoverImage2" style="width:100%" width="200">
  </div>
  <div>
    <img src="https://github.com/SidneyPrimas/Colorimetric_Chemical_Sensing/blob/master/diagram_real_capsule.png" alt="CoverImage2" style="width:100%" width="200">
  </div>
</div>  
