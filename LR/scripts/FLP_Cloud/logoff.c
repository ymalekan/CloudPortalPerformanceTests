logoff()
{
	
	lr_start_transaction("08_logoff");

	web_add_auto_header("Accept-Language", 
		"en");

	web_add_header("MaxDataServiceVersion", 
		"3.0");

	web_add_header("X-CSRF-Token",	"{x-csrf-token}");


	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.8");
	//You logged off from the system
	
	//web_reg_find("Text=location: /sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html" , LAST);
	
	web_url("logoff", 
		"URL={HOST}/sap/public/bc/icf/logoff", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={HOST}/sap/bc/ui5_ui5/ui2/ushell/shells/abap/FioriLaunchpad.html?sap-client=100&sap-language=EN", 
		"Snapshot=t99.inf", 
		"Mode=HTTP", 
		LAST);

	/* Request with GET method to URL "{HOST}/favicon.ico" failed during recording. Server response : 404*/

	lr_end_transaction("08_logoff",LR_AUTO);

	lr_think_time(tt);

	
	return 0;
}
