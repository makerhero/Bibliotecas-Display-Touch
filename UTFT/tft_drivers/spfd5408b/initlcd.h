case SPFD5408B:
	       
	      
	LCD_Write_COM_DATA(0x01, 0x0100);
	LCD_Write_COM_DATA(0x02, 0x0700);
	LCD_Write_COM_DATA(0x03, 0x1030);
	LCD_Write_COM_DATA(0x08, 0x0302);        
	LCD_Write_COM_DATA(0x09, 0x0000);        
	LCD_Write_COM_DATA(0x0A, 0x0008);
	      
	//-----Power On sequence----------------------- 
       
	LCD_Write_COM_DATA(0x10, 0x0790);        
	LCD_Write_COM_DATA(0x11, 0x0005);        
	LCD_Write_COM_DATA(0x12, 0x0000);        
	LCD_Write_COM_DATA(0x13, 0x0000);        
	//delay(50);
	LCD_Write_COM_DATA(0x10, 0x12B0); 
       // delay(50);
	LCD_Write_COM_DATA(0x11, 0x0007);        
	//delay(50);

	LCD_Write_COM_DATA(0x12, 0x008C);        
	LCD_Write_COM_DATA(0x13, 0x1700);        
	LCD_Write_COM_DATA(0x29, 0x0022);  
	                
              
	//delay(50);
	//-----Gamma control-----------------------        
	LCD_Write_COM_DATA(0x30, 0x0000);        
	LCD_Write_COM_DATA(0x31, 0x0505);        
	LCD_Write_COM_DATA(0x32, 0x0205);   
	LCD_Write_COM_DATA(0x35, 0x0206);        
	LCD_Write_COM_DATA(0x36, 0x0408);              
	LCD_Write_COM_DATA(0x37, 0x0000);        
	LCD_Write_COM_DATA(0x38, 0x0504);        
	LCD_Write_COM_DATA(0x39, 0x0206);        
	LCD_Write_COM_DATA(0x3C, 0x0206);        
	LCD_Write_COM_DATA(0x3D, 0x0408); 
       
	//-----Set RAM area-----------------------        
	LCD_Write_COM_DATA(0x50, 0x0000);
	LCD_Write_COM_DATA(0x51, 0x00EF);
	LCD_Write_COM_DATA(0x52, 0x0000);
	LCD_Write_COM_DATA(0x53, 0x013F);
	LCD_Write_COM_DATA(0x60, 0xA700);
	LCD_Write_COM_DATA(0x61, 0x0001);
	LCD_Write_COM_DATA(0x90, 0x0033);

      
	//***********************************************
       
	LCD_Write_COM_DATA(0x01, 0x0100);        
	LCD_Write_COM_DATA(0x07, 0x0133);
	LCD_Write_COM_DATA(0x02, 0x0700);
	LCD_Write_COM_DATA(0x03, 0x1030);
	LCD_Write_COM_DATA(0x08, 0x0302);        
	LCD_Write_COM_DATA(0x09, 0x0000);
        LCD_Write_COM_DATA(0x0A, 0x0008);
	
	LCD_Write_COM_DATA(0x10, 0x0790);        
	LCD_Write_COM_DATA(0x11, 0x0005);
	LCD_Write_COM_DATA(0x12, 0x0000);
	LCD_Write_COM_DATA(0x13, 0x0000);
        //***********************************************
	LCD_Write_COM_DATA(0x10, 0x12B0);        
	LCD_Write_COM_DATA(0x11, 0x0007);
	
        //***********************************************
        LCD_Write_COM_DATA(0x12, 0x008C);
	LCD_Write_COM_DATA(0x13, 0x1700);
        LCD_Write_COM_DATA(0x29, 0x0022);
        //-----------------------------------------------
        LCD_Write_COM_DATA(0x30, 0x0000);        
	LCD_Write_COM_DATA(0x31, 0x0505);        
	LCD_Write_COM_DATA(0x32, 0x0205);   
	LCD_Write_COM_DATA(0x35, 0x0206);        
	LCD_Write_COM_DATA(0x36, 0x0408);              
	LCD_Write_COM_DATA(0x37, 0x0000);        
	LCD_Write_COM_DATA(0x38, 0x0504);        
	LCD_Write_COM_DATA(0x39, 0x0206);        
	LCD_Write_COM_DATA(0x3C, 0x0206);        
	LCD_Write_COM_DATA(0x3D, 0x0408);
 
        LCD_Write_COM_DATA(0x50, 0x0000);
	LCD_Write_COM_DATA(0x51, 0x00EF);
	LCD_Write_COM_DATA(0x52, 0x0000);
	LCD_Write_COM_DATA(0x53, 0x013F);
	LCD_Write_COM_DATA(0x60, 0xA700);
	LCD_Write_COM_DATA(0x61, 0x0001);
	LCD_Write_COM_DATA(0x90, 0x0033);

      

	LCD_Write_COM_DATA(0x07, 0x0133);    
	     
    
	delay(50);
	break;
	