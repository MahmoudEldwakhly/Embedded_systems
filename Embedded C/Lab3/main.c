//@copyright:  Mahmoud Eldwakhly

// Toggle tiva's led  

#define SYSCTL_RCGC2_R  (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DIR_R  (*((volatile unsigned long*)0x40025400))    // 1 output, 0 input 
#define GPIO_PORTF_DEN_R  (*((volatile unsigned long*)0x4002551C))
#define GPIO_PORTF_DATA_R  (*((volatile unsigned long*)0x400253FC))

int main ()
{
    SYSCTL_RCGC2_R = 0x20; 
    // Delay to make sure GPIOF is up and running 
    volatile unsigned long delay_count; 
    
    for(delay_count = 0; delay_count < 200; delay_count++) ; 
    
    GPIO_PORTF_DIR_R |= 1<<3; // Set bit 3 of Port F to 1 to configure as output
    GPIO_PORTF_DEN_R  |= 1<<3; // Enable digital function on bit 3 of Port F

    while(1)	
    {
        GPIO_PORTF_DATA_R |= 1<<3;  // LED on 
        for(delay_count = 0; delay_count < 20000; delay_count++) ; 
        GPIO_PORTF_DATA_R &= ~(1<<3);  // LED off
        for(delay_count = 0; delay_count < 20000; delay_count++) ; 	
    }
	
    return 0;
}
