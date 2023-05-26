#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int p[], int n)
{
	int i, w;
	int K[n + 1][W + 1];

	for (i = 0; i <= n; i++) { //bottom-up manner
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(p[i - 1]
								+ K[i - 1][w - wt[i - 1]],
							K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}


int main() {
  int tn, W;
  scanf("%d %d", &tn, &W); // taking input

  int p[tn], wt[tn];
    for (int i = 0; i <tn; i++)
          scanf("%d", &p[i]);

  for (int i = 0; i < tn; i++)
    scanf("%d", &wt[i]);

	printf("%d", knapSack(W, wt, p, tn));
	return 0;
}