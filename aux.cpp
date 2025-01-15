vector<long long int > dp(M+1, 0);
for(int i = 1; i <= N; i++){
  for(int j = M; j >= 0; j--){
    if(costes[i-1].bollo <= j){
      int k = min(j/costes[i-1].bollo, costes[i-1].maxChorizo / costes[i-1].chorizo);

      for(int cont = 1; cont <= k; cont++){
        dp[j] = max(dp[j], dp[j - cont * costes[i-1].bollo] + cont * costes[i-1].beneficio)
      }
    }
  }
}

struct coste{
  int maxChorizo;
  int chorizo;
  int bollo;
  int beneficio;
}