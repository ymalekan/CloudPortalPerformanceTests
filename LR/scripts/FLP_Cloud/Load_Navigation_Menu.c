Load_Navigation_Menu()
{
	lr_start_transaction("05_Menu_Loading");

		web_url("PageSets", 
			"URL=https://{hostname}/v1/v1/nhs/filtered?siteId={site_id}",
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer={site_url}", 
			"Snapshot=t91.inf", 
			"Mode=HTTP", 
			LAST);

	lr_end_transaction("05_Menu_Loading", LR_AUTO );

	lr_think_time(tt);

	return 0;
}
