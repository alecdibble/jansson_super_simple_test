#include <jansson.h>
#include <stdio.h>



int main(int argc, char *argv[]) {
	printf("Starting jannson JSON tester\n");

	json_t *root, *root1;
	json_t *value, *value1;
	json_error_t error;
	char *messageText, *messageText1;

	printf("	Importing json string test\n");
	root = json_loads("{\"hello\":\"world\"}",0, &error);

	value = json_object_get(root, "hello");
	messageText = json_string_value(value);	
	printf("Test suceeds if \"world\" prints: %s\n", messageText);

	printf("	Saving to file test\n");

	if(json_dump_file(root, "/tmp/json_out_1", JSON_ENSURE_ASCII) < 0) {
		printf("Saving to file test failure\n");
	}
	else {
		printf("Saving to file test successful\n");
	}

	
	printf("	Loading from file test\n");

	root1 = json_load_file("/tmp/json_out_1", 0, &error);
	if(!root1){
		printf("Loading file test failed\n");
	}
	
	value1 = json_object_get(root1, "hello");
	messageText1 = json_string_value(value1);	
	printf("Test suceeds if \"world\" prints: %s\n", messageText1);
	return 0;
}
