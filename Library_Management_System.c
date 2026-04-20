#include <stdio.h>
#define MAX 50
int id[MAX], count = 0;
char name[MAX][40];
int st[MAX], top = -1;
int q[MAX], f = 0, r = -1;
void add()
 {
    printf("ID: ");
     scanf("%d", &id[count]);
    printf("Name: ");
     scanf(" %[^\n]", name[count]);
    st[++top] = id[count];
    count++;
}
void show()
 {
    for (int i = 0; i < count; i++)
        printf("%d %s\n", id[i], name[i]);
}
void search()
 {
    int x, ok = 0; printf("ID: ");
     scanf("%d", &x);
    for (int i = 0; i < count; i++)
        if (id[i] == x)
{
    printf("Found: %s\n", name[i]); ok = 1;
     }
    if (!ok)
    printf("Not Found\n");
}
void issue()
{
     int x; printf("ID: "); scanf("%d", &x); q[++r] = x;
     }
void process()
{
    if (f > r) printf("Empty\n");
    else printf("Issued: %d\n", q[f++]);
}
void undo()
 {
    if (top == -1) return;
    int x = st[top--];
    for (int i = 0; i < count; i++)
        if (id[i] == x) {
            for (int j = i; j < count - 1; j++)
{
    id[j] = id[j + 1];
    for (int k = 0; k < 40; k++) name[j][k] = name[j + 1][k];
        }
    count--; break;
        }
}
int main()
{
    int c;
    while (1)
        {
        printf("\n1.Add 2.Show 3.Search 4.Issue 5.Process 6.Undo 7.Exit\n");
        scanf("%d", &c);
        if (c == 1) add();
        else if (c == 2) show();
        else if (c == 3) search();
        else if (c == 4) issue();
        else if (c == 5) process();
        else if (c == 6) undo();
        else break;
        }
return 0;
}
