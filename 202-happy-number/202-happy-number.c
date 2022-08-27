

bool isHappy(int n){
    int* table = malloc(0);
    int index = 0;
    int new;
    while(1)
    {
        new = 0;
        // Do the process generate the new number
        while(n != 0)
        {
            new += (n % 10) * (n % 10);
            n /= 10;
        }
        
        // return if get a 1
        if (new == 1) return true;
        
        // Check if the number was showed before
        for(int i = 0; i < index; i++)
        {
            if (table[i] == new) return false;
        }
        
        // If not, add the new number into the table
        table = realloc(table, sizeof(int) * (index + 1));
        table[index++] = new;
        n = new;
    }
}