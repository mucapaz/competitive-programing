gets(linha);
int n = 0;
for (char* aux = strtok(linha, " "); aux; aux = strtok(NULL, " ")) {
   sscanf(aux, "%d", &arr[n++]);
}
