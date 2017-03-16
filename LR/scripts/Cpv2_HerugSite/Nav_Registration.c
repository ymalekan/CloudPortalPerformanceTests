Nav_Registration()
{
	lr_start_transaction("005_Nav_Registration");
	
	lr_end_transaction("005_Nav_Registration" , LR_AUTO);
	
	lr_think_time(tt);
			
	return 0;
}
