char* convert(char* s, int numRows) {
    int len, tail;
    int i = 0, j = 0, k = 0;
    char* ans;
    int columns, groups, nums_in_a_group, extra_num, columns_in_a_group;
    bool is_ordinary_line = false;
    
    if(numRows <= 0 || s == NULL) {
        return NULL;
    }
    
    len = strlen(s);
	ans = malloc(len + 1);
	memset(ans, 0, len + 1);

    if(numRows == 1 || numRows >= len) {
        memcpy(ans,s,len);
        return ans;
    }
    
    tail = len - 1;
    extra_num = numRows - 2;
    nums_in_a_group = numRows + extra_num;
    groups = (tail / nums_in_a_group) + 1;
    columns_in_a_group = extra_num + 1;
    columns = groups * columns_in_a_group;
    
    char** str_builder;
    char** str_builder_free;
    int* str_builder_len;
    int* str_builder_len_free;
    str_builder = malloc(sizeof(char*) * numRows);
    str_builder_free = str_builder;
    for(i = 0; i < numRows; i++) {
        str_builder[i] = malloc(columns);
    	memset(str_builder[i], 0, columns);
    }

    str_builder_len = (int*) malloc(sizeof(int) * numRows);
    str_builder_len_free = str_builder_len;
    memset(str_builder_len, 0, sizeof(int) * numRows);

    int row_loop_start_index;
    for(i = 0; i < columns; i++) {
    	is_ordinary_line = (i % columns_in_a_group == 0) ? true : false;
    	if(is_ordinary_line) {
			for(j = 0; j < numRows; j++) {
	            if(k >= len)    break;
	            str_builder[j][str_builder_len[j]++] = s[k++];
	        }
	        row_loop_start_index = numRows - 2;    		
    	} else {
    		if(k >= len)    break;
    		str_builder[row_loop_start_index][str_builder_len[row_loop_start_index]++] = s[k++];
    		row_loop_start_index--;
    	}
        
    }

    k = 0;
    for(i = 0; i < numRows; i++) {
        memcpy(&ans[k],str_builder[i],str_builder_len[i]);
        k += str_builder_len[i];
    }

    free(str_builder_free);
    free(str_builder_len_free);
    return ans;
}