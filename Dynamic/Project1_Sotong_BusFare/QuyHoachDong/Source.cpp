#include <stdio.h>

long Answer;
int Fare[11];
int Distance=0;
int T,N;
int F[11][10001];

int min(int a,int b){
	return ((a<b) ? a : b);
}
int main(void)
{
	int i,j,test_case;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		int i,j,temp;
		N=10;
		for (i = 1; i <= N; i++)scanf("%d", &Fare[i]);
		scanf("%d", &Distance);
		for(j=1;j<=Distance;j++)
			F[1][j]=Fare[1]*j;

		for(i=2;i<=10;i++){
			for(j=1;j<=Distance;j++){
				if(j<i) F[i][j]=F[i-1][j];
					else F[i][j]=min(F[i-1][j],F[i][j-i]+Fare[i]);
			}
		}		
		printf("Case #%d\n%d\n",test_case, F[10][Distance]);
 	}
	return 0;
}
