Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-GB,en;q=0.9");

	web_url("www.demoblaze.com", 
		"URL=https://www.demoblaze.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_url("config.json", 
		"URL=https://www.demoblaze.com/config.json", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	

	
	web_url("entries", 
		"URL=https://api.demoblaze.com/entries", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);


	web_custom_request("bycat", 
		"URL=https://api.demoblaze.com/bycat", 
		"Method=OPTIONS", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param_ex("paramName=Laptops","LB=\"title\":\"","RB=\"","ordinal=all",LAST);

	web_custom_request("bycat_2", 
		"URL=https://api.demoblaze.com/bycat", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"cat\":\"notebook\"}", 
		LAST);

	return 0;
}