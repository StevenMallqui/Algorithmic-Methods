  
  #include <Pair>

 
  
  Matriz<Pair<int,int>> matriz2 (<-1,-1>);
  matriz[0][0] = <0, 0>; 

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; i++){
      if(matriz2[i][j] != <-1,-1>){
        matriz2[i + matriz1[i][j]][j] = <i,j>;
        matriz2[i][j + matriz1[i][j].valor] = <i,j>;

      }
    }
  }