


/*Seven_Segment_Desplay(Seconds);	
Value1=BUTTON_GET_VALUE(Button_0);

									if(Value1==0)
									{
										Seconds++;
										Seven_Segment_Desplay(Seconds);
									}
									
Value2=BUTTON_GET_VALUE(Button_1);
									
									if (Value2==0 && Value1==1)
									{
										for(Seconds;Seconds>=0;Seconds--)
										{
											for (counter=0;counter<500;counter++)
											{
												Seven_Segment_Desplay(Seconds);
											}
											if (Seconds==0)
											{
												Seconds=0;
												Seven_Segment_Desplay(Seconds);
												LED_TOGGLE(LED_BLUE);
												BUZZER_ON();
												_delay_ms(5000);
												LED_TOGGLE(LED_BLUE);
												BUZZER_OFF();
												break;
											}
										}
									}*/