  
  float total = 0;

  int antalTotal = 0;
  for (int i = 0; i < counter; i++) {
    printf("\t\t=======\n");
    printf("\t\tVare nummer:%d\n",vareNr[i]);
    printf("\t\tAntal:%d\n",antal[i]);
    printf("\t\tPris/stk:%d\n",pris[i]);
    total += antal[i]*pris[i];
    antalTotal += antal[i];
    printf("\t\tantaltotal: %d\n",antalTotal);
  } //end of for loop (print varer)
  
  if(total > 500)
  {
    total = total * 0.9;
  }
  else if (total < 200 )
  {
    total += 50;
  }

  printf("\n\t\ttotal:%f\n",total);

