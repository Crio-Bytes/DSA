#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define DEBUG 0
//#define STRING_COUNT 10
#define TEXT_LENGTH 1000
#define PATTERN_LENGTH 100

void initialize_string(char*, int);
void get_text_pattern(char*, char*, int);
void initialize_string(char*, int);
int RabinKarp(const char* , const char* );
int KMP(const char* , const char* );
void computeLPS(const char*, int ,int* );
void display_result(const int , const long, const int, const long);

// call this function to start a nanosecond-resolution timer
struct timespec timer_start(){
	struct timespec start_time;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
	return start_time;
}
// call this function to end a timer, returning nanoseconds elapsed as a long
long timer_end(struct timespec start_time){
	struct timespec end_time;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);
	long diffInNanos = (end_time.tv_sec - start_time.tv_sec) * (long)1e9 + (end_time.tv_nsec - start_time.tv_nsec);
	return diffInNanos;
}

int main(){
    char case_choice;
    int m;
    int n;
    int flag = 1;
    char* text;
    char* pattern;
    int result_KMP;
    int result_RB;

    long time_elapsed_nanos_KMP;
    long time_elapsed_nanos_RB;
    struct timespec vartime;

    int (*algorithms[])(const char* text, const char* pattern) = {
        RabinKarp, KMP
    };

    while(flag){
        printf("------------------------\nSelect a time complexity\nBest case - 0\nAverage Case - 1\nWorst Case - 2\nCustom Case (user input) - 3\nAny Character for exit\n------------------------\n");
        scanf(" %c",&case_choice);
        switch(case_choice){
            case '0':
                text = (char*)malloc(sizeof(char)*(TEXT_LENGTH+1));
                pattern = (char*)malloc(sizeof(char)*(PATTERN_LENGTH+1));
                initialize_string(text,TEXT_LENGTH);
                initialize_string(pattern,PATTERN_LENGTH);
                get_text_pattern(text,pattern,0);
                if(DEBUG){
                    printf("[0] Best Case\n");
                    printf("%s\n%s\n",text,pattern);
                }

                vartime = timer_start();
                result_RB = algorithms[0](text, pattern);
                time_elapsed_nanos_RB = timer_end(vartime);
                vartime = timer_start();
                result_KMP = algorithms[1](text, pattern);
                time_elapsed_nanos_KMP = timer_end(vartime);
                display_result(result_RB, time_elapsed_nanos_RB, result_KMP, time_elapsed_nanos_KMP);
                break;
            case '1':
                text = (char*)malloc(sizeof(char)*(TEXT_LENGTH+1));
                pattern = (char*)malloc(sizeof(char)*(PATTERN_LENGTH+1));
                initialize_string(text,TEXT_LENGTH);
                initialize_string(pattern,PATTERN_LENGTH);
                get_text_pattern(text,pattern,1);
                if(DEBUG){
                    printf("[1] Average Case\n");
                    printf("%s\n%s\n",text,pattern);
                }
                vartime = timer_start();
                result_RB = algorithms[0](text, pattern);
                time_elapsed_nanos_RB = timer_end(vartime);
                vartime = timer_start();
                result_KMP = algorithms[1](text, pattern);
                time_elapsed_nanos_KMP = timer_end(vartime);
                display_result(result_RB, time_elapsed_nanos_RB, result_KMP, time_elapsed_nanos_KMP);
                break;
            case '2':
                text = (char*)malloc(sizeof(char)*(TEXT_LENGTH+1));
                pattern = (char*)malloc(sizeof(char)*(PATTERN_LENGTH+1));
                initialize_string(text,TEXT_LENGTH);
                initialize_string(pattern,PATTERN_LENGTH);
                get_text_pattern(text,pattern,2);
                if(DEBUG){
                    printf("[2] Worst Case\n");
                    printf("%s\n%s\n",text,pattern);
                }
                vartime = timer_start();
                result_RB = algorithms[0](text, pattern);
                time_elapsed_nanos_RB = timer_end(vartime);
                vartime = timer_start();
                result_KMP = algorithms[1](text, pattern);
                time_elapsed_nanos_KMP = timer_end(vartime);
                display_result(result_RB, time_elapsed_nanos_RB, result_KMP, time_elapsed_nanos_KMP);
                break;
            case '3':
                if(DEBUG){
                    printf("[3] Custom Input\n");
                }
                printf("Enter size of text\n");
                scanf("%d",&n);
                text = (char*)malloc(sizeof(char)*(n+1));
                
                printf("Enter text\n");
                scanf("%s",text);
                text[n] = '\0';

                printf("\nEnter size of pattern\n");
                scanf("%d",&m);
                pattern = (char*)malloc(sizeof(char)*(m+1));

                printf("Enter pattern\n");
                scanf("%s",pattern);
                pattern[m] = '\0';

                vartime = timer_start();
                result_RB = algorithms[0](text, pattern);
                time_elapsed_nanos_RB = timer_end(vartime);
                vartime = timer_start();
                result_KMP = algorithms[1](text, pattern);
                time_elapsed_nanos_KMP = timer_end(vartime);
                display_result(result_RB, time_elapsed_nanos_RB, result_KMP, time_elapsed_nanos_KMP);
                break;
            default: 
                flag = 0;
                break;    
        }
        
    }
    free(text);  
    free(pattern);
    return 0;
}
void display_result(const int result_RB, const long time_elapsed_nanos_RB, const int result_KMP, const long time_elapsed_nanos_KMP){
    printf("------------------------\nPattern occurs at %d th index\n",result_RB);
    printf("Time taken by Rabin Karp Algorithm = %ld\n\n", time_elapsed_nanos_RB);
    printf("Pattern occurs at %d th index\n",result_KMP);
    printf("Time taken by KMP Algorithm = %ld\n------------------------\n", time_elapsed_nanos_KMP);
}
void initialize_string(char* string, int m){
    for(int i = 0; i < m; i++){
        string[i] = '0';
    }
    string[m] = '\0';
}

void get_text_pattern(char* text, char* pattern, int c){  
    char og_text[TEXT_LENGTH+1];
    strcpy(og_text,"cababaaabcacaccacacbcbbabcccccbbbaabaabcccaccccbabaacabbaabbaaccaaccccbbcbccaacaacbcbacccbabacacbcabaaabaccccacaacbcbbccbbcbbcabbbaacaababaacbbccaccbacaaabaccbbbcacbaaabccacbcaabccacaccbcaaabcabacaacbcabcbbccacbabbccbacbcbbacbcaaabacccacabbbcbbbabcbbbbbbbbbbbccaccaaaccaccacccbbbcabbccaaaaabbaacabacbbabcabcabbccccabbcbbaacaaaaccaaaccabccbcbabcacaaaabaacaacbaccaabaaabbbabaccbaaabbcacbaaabbabccbbcaabaccbbcacccccacabbbaaccabbbacaabcccabaacaaaccaccbbbcbacbacaababbacbbbbbbbaabacbabcabcccbaaabbbabacbaabacacbaabbacabaccacbbcaaccaaacbabcaacabcabaccababcabcbbabcacbbaaabaaacacaaaabbaccabcaccccabbaaabbbbcacccabcbbbbabcbacbcbcacbbcbcbabaccbacbaaaaabbbbbbcaabcbacbacbcaaccbcbbbabbcbbbcbcabababbbaabbaaacaacabbabbbccabbcabacabcbbaaaacbbbaccababbccbabbbbccccaabccbbcbcccbaabbbbcbcbabaaccbccbbbacabacbbababbcccbaaabbbabcabbbbaabaacccacabbabccaccbbbcbaccacacbbacabcbcccbacabbaccacbcbacaacbcaabbbcbccbaabbaabbaacbbcccaaacabcaaccbbbbbcaaccabcbacbbbcbbccaccccbbcabbbccbaacaccabacbacbabcbbbbccbabbaacccacaacbaacbbb\0");
    
    for(int i = 0; i < TEXT_LENGTH; i++){
       text[i] = og_text[i];
    }
    int start = 0;
    if(c == 0){
        start = 0;
    }else if(c == 1){
        start = 500;
    }else{
        start = 900;
    }
    
    for(int m = start; m < start + PATTERN_LENGTH; m++){
        pattern[m-start] = text[m];
    }
}

int RabinKarp(const char* text, const char* pattern){
    if(DEBUG){
        printf("[RabinKarp] text = %s\n",text);
        printf("[RabinKarp] pattern = %s\n",pattern);
    }
    int n = strlen(text);
    int m = strlen(pattern);
    int i;
    int j;
    int q = 1000000007;
    long long int p_hash = 0;
    long long int t_hash = 0;
    long long int h = 1;
    int d = 256; //radix

    for(i = 0; i < m-1; i++){
        h = (h*d)%q;
    }
    for(i = 0; i < m; i++){
        p_hash = (p_hash*d + (int)pattern[i])%q;
        t_hash = (t_hash*d + (int)text[i])%q;
    }
    for(i = 0; i <= n-m; i++){
        if(p_hash == t_hash){
            for(j = 0; j < m; j++){
                if(text[i+j] != pattern[j])
                    break;
            }
            if(j == m){
                return i;
            }
        }
        if(i < n-m){
            t_hash = (d*(t_hash - (int)text[i]*h) + (int)text[i+m])%q;
            if(t_hash < 0)
                t_hash += q;
        }
    }
    return -1;
}
int KMP(const char* text, const char* pattern){
    if(DEBUG){
        printf("[KMP] text = %s\n",text);
        printf("[KMP] pattern = %s\n",pattern);
    }
    int n = strlen(text);
    int m = strlen(pattern);
    if(m > n)
        return -1;
    int* lps = (int*)malloc(sizeof(int)*m);
    int i;
    for(i = 0; i < m; i++){
        lps[i] = 0;
    }
    i = 0;
    int j = 0;
    computeLPS(pattern,m,lps);
    while(i < n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            return i-j;
        }else if(i < n && text[i] != pattern[j]){
            if(j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }    
    }
    free(lps);
    return -1;
}
void computeLPS(const char* pattern, int m,int* lps){
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while(i < m){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}