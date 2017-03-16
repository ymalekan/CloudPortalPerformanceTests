Nav_Agenda()
{
	lr_start_transaction("004_Nav_Agenda");
	
	lr_end_transaction("004_Nav_Agenda" , LR_AUTO);
	
	lr_think_time(tt);
			
	return 0;
}
