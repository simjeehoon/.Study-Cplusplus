
typedef struct _account
{
	char acc_id[100];
	char name[100];
	int balance;
}Account;

void establish(Account ** alloc_mem, int * count_member);
void deposit(Account * alloc_mem, const int count_member);
void withdraw(Account * alloc_mem, const int count_member);
void all_print(Account * alloc_mem, const int count_member);