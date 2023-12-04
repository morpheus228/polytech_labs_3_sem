void SetPlus(int a, int b) {
    int n = 0;
    int temp = a;

    do {
        temp=Find(temp);
        n++;
    }
    while (temp!=0);

    temp=b;

    for (int i=0; i<n; i++) {
        temp = Plus[1][temp];
        if (temp==0 && a!=0) PlusP[a][b]=1;
    }
    
    Plus[a][b]=temp;
}
