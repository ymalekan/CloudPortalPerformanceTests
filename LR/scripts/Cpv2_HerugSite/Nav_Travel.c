Nav_Travel()
{
	lr_start_transaction("006_Nav_Travel");
	
	lr_end_transaction("006_Nav_Travel" , LR_AUTO);
	
	lr_think_time(tt);
			
	return 0;
}
