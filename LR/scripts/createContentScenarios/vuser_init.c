/*================================================*/
/*
int totalNumberOfUI5Apps = 45;
int UI5appsPerCatalog = 3;

int totalNumberOfWDAApps = 30;
int WDAappsPerCatalog = 3;

int totalNumberOfSAPGUIApps = 25;
int SAPGUIappsPerCatalog = 5;
*/
/*================================================*/

int totalNumberOfUI5Apps = 0;
int UI5appsPerCatalog = 20;

int totalNumberOfWDAApps = 0;
int WDAappsPerCatalog = 20;
//int totalNumberOfWDAApps = 3500;
//int WDAappsPerCatalog = 20;

int totalNumberOfSAPGUIApps = 1000;
int SAPGUIappsPerCatalog = 20;
//int totalNumberOfSAPGUIApps = 3500;
//int SAPGUIappsPerCatalog = 20;

/*================================================*/

int totalNumberOfUI5Groups;
int totalNumberOfUI5Catalogs;
int totalNumberOfWDACatalogs;
int totalNumberOfWDAGroups;
int totalNumberOfSAPGUICatalogs;
int totalNumberOfSAPGUIGroups;


int index;
int tt;
int totalNumberOfApps=0;

char appBuffer[5000] = "";
char appId[5000] = "";
int appCounter;
char appsList[10000] = "";
char tilesList[10000] = "";

char buffer[5000] = "";
char uuid[5000] = "";
int counter;

char catalogsList[10000] = "";
char groupsList[10000] = "";

int roundup(int apps, int groups){
	int i = apps/groups;
	int mod = apps % groups;
	if (mod > 0){ i++; }
	
	return i;
}

vuser_init()
{

	totalNumberOfUI5Catalogs = roundup(totalNumberOfUI5Apps, UI5appsPerCatalog);
	totalNumberOfUI5Groups = totalNumberOfUI5Catalogs;

	totalNumberOfWDACatalogs = roundup(totalNumberOfWDAApps, WDAappsPerCatalog);
	totalNumberOfWDAGroups = totalNumberOfWDACatalogs;

	totalNumberOfSAPGUICatalogs = roundup(totalNumberOfSAPGUIApps, SAPGUIappsPerCatalog);
	totalNumberOfSAPGUIGroups = totalNumberOfSAPGUICatalogs;
	
	
	totalNumberOfApps = totalNumberOfUI5Apps + totalNumberOfWDAApps + totalNumberOfSAPGUIApps;
	
	web_save_timestamp_param("timestamp",LAST);
		
	web_set_sockets_option("SSL_VERSION", "TLS");
    web_set_sockets_option("OVERLAPPED_SEND", "0");
    web_set_sockets_option("IGNORE_PREMATURE_SHUTDOWN", "1");


	tt = atoi((lr_get_attrib_string("THINK_TIME")));
	lr_save_string(lr_get_attrib_string("HOST"), "hostname");
	lr_save_string(lr_get_attrib_string("account"), "account");	
				
	web_set_sockets_option("MAX_TOTAL_CONNECTIONS" , "6");
	web_set_sockets_option("MAX_CONNECTIONS_PER_HOST" , "6");
	web_set_max_html_param_len("10485760");
	web_add_auto_header("Accept-Language", "en-US,en;q=0.8");
	//web_add_auto_header("Upgrade-Insecure-Requests", "1");
	
	return 0;
}

char* getSaltedId(char *buffer, int id, char *UUId, char *elementType){
	itoa(id,buffer,10);

	// AppId Salting - all UUIDs will be consecutive in value and of length 50 as is standard, starting from 1 and ending with 512
	switch(strlen(buffer))
		{
		case 1 :
			if (strcmp(elementType, "UI5_app") == 0) {
				sprintf(buffer, "UI5APP00000000000000000000000000%d", id);
			}
			else if (strcmp(elementType, "UI5_catalog") == 0) {
				sprintf(buffer, "CATALOG0-UI50-0000-0000-000000000000-000000000000%d", id);								 
			}
			else if (strcmp(elementType, "UI5_group") == 0) {
				sprintf(buffer, "GROUP000-UI50-0000-0000-000000000000-000000000000%d", id);
			}
			else if (strcmp(elementType, "UI5_tile") == 0) {
				sprintf(buffer, "TILE0000-UI50-0000-0000-000000000000-000000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_app") == 0) {
				sprintf(buffer, "APP00000-WDA0-0000-0000-000000000000-000000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_catalog") == 0) {
				sprintf(buffer, "CATALOG0-WDA0-0000-0000-000000000000-000000000000%d", id);								 
			}
			else if (strcmp(elementType, "WDA_group") == 0) {
				sprintf(buffer, "GROUP000-WDA0-0000-0000-000000000000-000000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_tile") == 0) {
				sprintf(buffer, "TILE0000-WDA0-0000-0000-000000000000-000000000000%d", id);
			}				
			else if (strcmp(elementType, "SAPGUI_app") == 0) {
				sprintf(buffer, "APP00000-GUI0-0000-0000-000000000000-000000000000%d", id);
			}
			else if (strcmp(elementType, "SAPGUI_catalog") == 0) {
				sprintf(buffer, "CATALOG0-GUI0-0000-0000-000000000000-000000000000%d", id);								 
			}
			else if (strcmp(elementType, "SAPGUI_group") == 0) {
				sprintf(buffer, "GROUP000-GUI0-0000-0000-000000000000-000000000000%d", id);
			}
			else if (strcmp(elementType, "SAPGUI_tile") == 0) {
				sprintf(buffer, "TILE0000-GUI0-0000-0000-000000000000-000000000000%d", id);
			}	
			else {
				sprintf(buffer, "00000000-0000-0000-0000-00000000000%d", id); 
			}
			strcpy(UUId, buffer);
    		break;
    case 2 :
 			if (strcmp(elementType, "UI5_app") == 0) {
				sprintf(buffer, "UI5APP0000000000000000000000000%d", id);
			}
			else if (strcmp(elementType, "UI5_catalog") == 0) {
				sprintf(buffer, "CATALOG0-UI50-0000-0000-000000000000-0000000000%d", id);								 
			}
			else if (strcmp(elementType, "UI5_group") == 0) {
				sprintf(buffer, "GROUP000-UI50-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "UI5_tile") == 0) {
				sprintf(buffer, "TILE0000-UI50-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_app") == 0) {
				sprintf(buffer, "APP00000-WDA0-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_catalog") == 0) {
				sprintf(buffer, "CATALOG0-WDA0-0000-0000-000000000000-0000000000%d", id);								 
			}
			else if (strcmp(elementType, "WDA_group") == 0) {
				sprintf(buffer, "GROUP000-WDA0-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_tile") == 0) {
				sprintf(buffer, "TILE0000-WDA0-0000-0000-000000000000-0000000000%d", id);
			}				
			else if (strcmp(elementType, "SAPGUI_app") == 0) {
				sprintf(buffer, "APP00000-GUI0-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "SAPGUI_catalog") == 0) {
				sprintf(buffer, "CATALOG0-GUI0-0000-0000-000000000000-0000000000%d", id);								 
			}
			else if (strcmp(elementType, "SAPGUI_group") == 0) {
				sprintf(buffer, "GROUP000-GUI0-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "SAPGUI_tile") == 0) {
				sprintf(buffer, "TILE0000-GUI0-0000-0000-000000000000-0000000000%d", id);
			}	
			else {
				sprintf(buffer, "00000000-0000-0000-0000-0000000000%d", id); 
			}
    		strcpy(UUId, buffer);
	       	break;
		case 3 :
			if (strcmp(elementType, "UI5_app") == 0) {
				sprintf(buffer, "UI5APP000000000000000000000000%d", id);
			}
			else if (strcmp(elementType, "UI5_catalog") == 0) {
				sprintf(buffer, "CATALOG0-UI50-0000-0000-000000000000-0000000000%d", id);								 
			}
			else if (strcmp(elementType, "UI5_group") == 0) {
				sprintf(buffer, "GROUP000-UI50-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "UI5_tile") == 0) {
				sprintf(buffer, "TILE0000-UI50-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_app") == 0) {
				sprintf(buffer, "APP00000-WDA0-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_catalog") == 0) {
				sprintf(buffer, "CATALOG0-WDA0-0000-0000-000000000000-0000000000%d", id);								 
			}
			else if (strcmp(elementType, "WDA_group") == 0) {
				sprintf(buffer, "GROUP000-WDA0-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_tile") == 0) {
				sprintf(buffer, "TILE0000-WDA0-0000-0000-000000000000-0000000000%d", id);
			}				
			else if (strcmp(elementType, "SAPGUI_app") == 0) {
				sprintf(buffer, "APP00000-GUI0-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "SAPGUI_catalog") == 0) {
				sprintf(buffer, "CATALOG0-GUI0-0000-0000-000000000000-0000000000%d", id);								 
			}
			else if (strcmp(elementType, "SAPGUI_group") == 0) {
				sprintf(buffer, "GROUP000-GUI0-0000-0000-000000000000-0000000000%d", id);
			}
			else if (strcmp(elementType, "SAPGUI_tile") == 0) {
				sprintf(buffer, "TILE0000-GUI0-0000-0000-000000000000-0000000000%d", id);
			}	
			else {
				sprintf(buffer, "00000000-0000-0000-0000-000000000%d", id); 
			}
    		strcpy(UUId, buffer);
	       	break;
	  	case 4 :
			if (strcmp(elementType, "UI5_app") == 0) {
				sprintf(buffer, "UI5APP00000000000000000000000%d", id);
			}
			else if (strcmp(elementType, "UI5_catalog") == 0) {
				sprintf(buffer, "CATALOG0-UI50-0000-0000-000000000000-000000000%d", id);								 
			}
			else if (strcmp(elementType, "UI5_group") == 0) {
				sprintf(buffer, "GROUP000-UI50-0000-0000-000000000000-000000000%d", id);
			}
			else if (strcmp(elementType, "UI5_tile") == 0) {
				sprintf(buffer, "TILE0000-UI50-0000-0000-000000000000-000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_app") == 0) {
				sprintf(buffer, "APP00000-WDA0-0000-0000-000000000000-000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_catalog") == 0) {
				sprintf(buffer, "CATALOG0-WDA0-0000-0000-000000000000-000000000%d", id);								 
			}
			else if (strcmp(elementType, "WDA_group") == 0) {
				sprintf(buffer, "GROUP000-WDA0-0000-0000-000000000000-000000000%d", id);
			}
			else if (strcmp(elementType, "WDA_tile") == 0) {
				sprintf(buffer, "TILE0000-WDA0-0000-0000-000000000000-000000000%d", id);
			}				
			else if (strcmp(elementType, "SAPGUI_app") == 0) {
				sprintf(buffer, "APP00000-GUI0-0000-0000-000000000000-000000000%d", id);
			}
			else if (strcmp(elementType, "SAPGUI_catalog") == 0) {
				sprintf(buffer, "CATALOG0-GUI0-0000-0000-000000000000-000000000%d", id);								 
			}
			else if (strcmp(elementType, "SAPGUI_group") == 0) {
				sprintf(buffer, "GROUP000-GUI0-0000-0000-000000000000-000000000%d", id);
			}
			else if (strcmp(elementType, "SAPGUI_tile") == 0) {
				sprintf(buffer, "TILE0000-GUI0-0000-0000-000000000000-000000000%d", id);
			}	
			else {
				sprintf(buffer, "00000000-0000-0000-0000-00000000%d", id); 
			}
    		strcpy(UUId, buffer);
	       	break;
	}
	return UUId;
}

