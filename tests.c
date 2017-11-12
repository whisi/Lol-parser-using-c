#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parson.h"    // parson.h 헤더 파일 포함
#include "type_definitions.h"

void print_commits_info(const char *username) {
    JSON_Value *root_value;
    JSON_Array *arrays;
    JSON_Object *rootObjects;
    
    char curl_command[512];
    char cleanup_command[256];
    char output_filename[] = "lol.json";
    char api_key[] = "RGAPI-48c892d1-0ce3-45e5-8455-3dc3ecd1ff04";
    /* it ain't pretty, but it's not a libcurl tutorial */
    sprintf(curl_command, 
        "curl -s \"https://kr.api.riotgames.com/lol/summoner/v3/summoners/by-account/%s/?api_key=%s\" > %s",
        username, api_key, output_filename);
	//sprintf(cleanup_command, "rm -f %s", output_filename);
    system(curl_command);
    
    /* parsing json and validating output */
    root_value = json_parse_file(output_filename);
    /*
	if (json_value_get_type(root_value) != JSONArray) {
        system(cleanup_command);
        return;
    }*/
	
    rootObjects = json_value_get_object(root_value);
	printf("name : %s\n", json_object_get_string(rootObjects, "name"));
	printf("level : %f\n", json_object_get_number(rootObjects, "summonerLevel"));
    
    /* cleanup code */
	/*
    json_value_free(root_value);
    system(cleanup_command);
	*/
}
int main()
{
	print_commits_info("439488");
    return 0;
}
