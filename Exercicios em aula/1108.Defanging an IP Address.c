

char *defangIPaddr(char *address)
{
    int len = strlen(address);
    int cont = 0;

    for (int i = 0; i < len; i++)
    {
        if (address[i] == '.')
        {
            cont++;
        }
    }

    char *result = (char *)malloc(len + cont * 2 + 1);
    if (!result)
        return NULL;

    int j = 0;

    for (int i = 0; i < len; i++)
    {
        if (address[i] == '.')
        {
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
        }
        else
        {
            result[j++] = address[i];
        }
    }

    result[j] = '\0';
    return result;
}