  float total = 0;
  int forsendelse = 0;
  float rabat;
  int antalTotal = 0;
  for (int i = 0; i < counter; i++) {
    printf("\t\t=======\n");
    printf("\t\tVare nummer:%d\n",vareNr[i]);
    printf("\t\tAntal:%d\n",antal[i]);
    printf("\t\tPris/stk:%d\n",pris[i]);
    total += antal[i]*pris[i];
    antalTotal += antal[i];
  } //end of for loop (print varer)
  

  printf("\n\t\tsamlet pris:%f\n",total);
  if(total > 500)
  {
    rabat = total * 0.1;
    total *= 0.9;
  }
  else if (total < 200 || antalTotal < 3)
  {
    total += 50;
    forsendelse += 50;
  }
  
  printf("\n\t\tforsendelse:%d\n",forsendelse);
  printf("\n\t\trabat:%f\n",rabat);
  printf("\n\t\ttotal pris:%f\n",total);

