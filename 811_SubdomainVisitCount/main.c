#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

#define COUNT_MAX 10000
#define DOMAIN_NAME_LENGTH_MAX 100

struct node {
	int count;
	char domain_name[DOMAIN_NAME_LENGTH_MAX];
	struct node *next;
};

int travel_nodes(struct node *head)
{
	int node_num = 0;
	struct node *n = head;
	while (n != NULL) {
#ifdef DEBUG
		printf("count:%d domain_name:%s\n", n->count, n->domain_name);
#endif
		n = n->next;
		node_num++;
	}

	return node_num;
}

int is_domain_found(struct node *head, int cp_count, char * domain)
{
	int isFound = 0;

	struct node *n = head;
	while (n != NULL) {
		if (!strcmp(n->domain_name, domain)) {
			isFound = 1;
			n->count += cp_count;
			break;
		}
		n = n->next;
	}

	return isFound;
}

void insert_node_end(struct node *head, int cp_count, char * domain)
{
	struct node *n = head;
	struct node *inserted_node = malloc(sizeof(struct node));
	if (inserted_node == NULL)
		return;
	
	//find the end node
	while (n->next != NULL) {
		n = n->next;
	}
	
	n->next = inserted_node;
	inserted_node->count = cp_count;
	strcpy(inserted_node->domain_name, domain);
	inserted_node->next = NULL;
}

int getCount(char * domain)
{
	int i = 0, count = 0;
	char num[DOMAIN_NAME_LENGTH_MAX] = {'\0'};
	char *c = domain;
	char * pEnd;

	while ((*c != ' ') && (*c != '\0')) {
		num[i] = *c;
		i++;
		c++;
	}

	count = (int) strtol(num,&pEnd,10);

	return count;
}

void compose_result(struct node *head, char **result, int total_count)
{
	struct node *n= head;
	int i = 0;
	while (n != NULL) {
		char temp[DOMAIN_NAME_LENGTH_MAX];
		char num_str[20];
		sprintf(num_str, "%d ", n->count);
		strcpy(temp, num_str);
#ifdef DEBUG
		printf("temp:%s\n", temp);
#endif
		strcat(temp, n->domain_name);
#ifdef DEBUG
		printf("temp:%s\n", temp);
#endif
		strcpy((*(result+i)), temp);
		i++;
		n = n->next;
	}
}

void processCPDomain(char *cpdomain, int count, int *isListEmpty, struct node **head)
{
#ifdef DEBUG
	printf("The cpdomain is:%s\n", cpdomain);
	printf("The count is:%d\n", count);
#endif

	char *str1 = cpdomain;
	int is_domainFound;

	//ignore the space
	str1++;
	do {
#ifdef DEBUG
		printf("str1:%s strlen(str1):%d\n", str1, (int) strlen(str1));
#endif
		if (*isListEmpty == 1) {
			(*head)->count = count;
			strcpy((*head)->domain_name, str1);
			*isListEmpty = 0;
		}
		else {
			is_domainFound = is_domain_found(*head, count, str1);
			if (is_domainFound == 0) {
#ifdef DEBUG
				printf("no domain matched\n");
#endif
				insert_node_end(*head, count, str1);
			}
			else {
#ifdef DEBUG
				printf("domain [%s] matched\n", str1);
#endif
			}
		}

		str1 = strchr(str1, '.');
		if(str1 == NULL)
			break;
		else
			str1++; //ignore the dot
	} while (1);
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize) {
	int domain_count = 0;
	int isListEmpty = 1;

#ifdef DEBUG
	printf("cpdomainsSize:%d\n", cpdomainsSize);
#endif
	struct node *head = malloc(sizeof(struct node));
	if (head == NULL)
		return NULL;

	for (int i=0;i<cpdomainsSize;i++) {
		if (*(cpdomains+i) == NULL)
			break;
#ifdef DEBUG
		printf("cpdomains[%d]:%s\n", i, *(cpdomains+i));
#endif

		char temp_str[DOMAIN_NAME_LENGTH_MAX];
		strcpy(temp_str, *(cpdomains+i));
		//printf("temp_str:%s sizeof(temp_str):%d\n", temp_str, (int) strlen(temp_str));


		int count = getCount(temp_str);
		char *str1 = strchr(temp_str, ' ');
		if (str1 == NULL)
			continue;
		
#ifdef DEBUG
		printf("str1:%s strlen(str1):%d\n", str1, (int) strlen(str1));
#endif

		processCPDomain(str1, count, &isListEmpty, &head);;
#ifdef DEBUG
		printf("\n");
#endif
	}

	domain_count = travel_nodes(head);
#ifdef DEBUG
	printf("domain_count:%d\n", domain_count);
#endif

	char **result = (char **) malloc(sizeof(char *) * domain_count);
	if (result == NULL)
		return NULL;
	
	for (int i=0;i<domain_count;i++) {
		*(result+i) = (char*) malloc(sizeof(char) * DOMAIN_NAME_LENGTH_MAX);
		if ((result+i) == NULL)
			return NULL;
	}

	compose_result(head, result, domain_count);
	free(head);

	*returnSize = domain_count;

#ifdef DEBUG
	printf("final result:\n");
	for (int i=0;i<*returnSize;i++) {
		printf("result[%d]:%s\n", i, *(result+i));
	}
#endif

    return result;
}

int main(void)
{
	//char *Input[COUNT_MAX] = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
	//char *Input[COUNT_MAX] = {"3325 lrp.rbg.co","8712 jeq.iux.com","1146 auv.jtg.team","6992 lfn.us","1512 jnb.hwu.team","1556 ocf.ca","1105 zqk.us","219 ser.team","1227 ytn.us","484 mgu.rbg.org","3855 cdv.jkx.net","7872 gqs.co","4870 jnk.mkw.net","7682 wqv.net","8013 btv.team","2854 ena.zfz.co","883 tgr.bfo.network","6878 llq.ksc.com","480 gjf.co","4823 knr.gdw.org","6222 hal.ca","94 zqk.com","1623 gxz.team","6512 hwu.ca","841 irv.network","267 xhe.network","4658 zqk.com","3665 gqi.network","5638 ihs.gxz.us","5063 fly.org","1493 jaz.kwd.co","9917 dze.tjy.ca","227 ois.gbq.co","7382 ser.network","3554 kup.vbo.us","222 eei.ara.ca","3042 gbq.com","928 kye.gjf.ca","6874 coo.yvs.co","5105 blt.gxj.net","8165 smw.dfa.co","3341 lwa.zfz.org","6290 wuq.fff.com","3685 wip.network","7549 dfa.com","425 tna.gqi.ca","301 kmz.us","9933 gas.srp.network","3054 irv.org","4678 prl.gqs.org","6065 cfv.nva.net","9587 kmx.us","9267 lmm.network","3363 tgg.epf.network","7320 fzx.com","7838 uzz.tnr.net","8399 yyw.qgx.net","2849 aon.co","72 gnr.tjy.us","5679 jfz.net","7969 bgq.wqv.com","7457 soq.wsv.network","8067 ajl.com","4420 ulz.us","2094 uyy.ca","1929 euz.zhy.org","2630 ocf.org","8328 wsv.team","3039 ksc.co","8160 ioc.okv.com","4898 rcz.ixi.com","374 rbg.ca","2846 ltq.net","2596 amr.com","4252 hwu.network","2451 ocf.team","6480 zhy.co","6117 gqi.net","4670 kmi.co","8838 jfz.us","4628 fuc.wph.org","9675 gqi.us","9437 wqv.ca","6940 lmm.org","5488 lbc.ulz.co","5859 tfm.us","7025 krx.arz.team","5231 xdm.jkx.team","512 arx.hkt.team","3061 xxp.uyy.com","9948 nkw.net","2838 buf.team","9513 jkx.co","1560 asq.cwn.team","6910 gjf.us","108 avl.buf.net","1781 hnl.co","7245 kam.ara.co","5864 ltq.team","9487 mhs.htq.org"};
	//char *Input[COUNT_MAX] = {"9656 hoh.ca","1311 sci.net","1945 jre.us","9323 kvk.com","8682 whf.unn.com","9895 xow.fsw.us","6881 epf.gdw.net","7566 gjf.network"};
	char *Input[COUNT_MAX] = {"9001 discuss.leetcode.com"};
	//char *Input[] = {"9001 discuss.leetcode.com"};
	int cpdomainsSize = COUNT_MAX;
	
	char ** ptr_i = Input;
	int returnSize = 0;

	printf("Input:\n");
	for (int i=0;i<cpdomainsSize;i++) {
		if (*(ptr_i+i) == NULL)
			break;
		printf("Input[%d]:%s\n", i, *(ptr_i+i));
	}

	char **Output = subdomainVisits(ptr_i, cpdomainsSize, &returnSize);
	printf("final result:\n");
	for (int i=0;i<returnSize;i++) {
		printf("Output[%d]:%s\n", i, *(Output+i));
	}

	return 0;
}

/*
Example 1:
Input: 
["9001 discuss.leetcode.com"]
Output: 
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation: 
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

Example 2:
Input: 
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output: 
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation: 
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

Notes:

The length of cpdomains will not exceed 100. 
The length of each domain name will not exceed 100.
Each address will have either 1 or 2 "." characters.
The input count in any count-paired domain will not exceed 10000.
The answer output can be returned in any order.

*/