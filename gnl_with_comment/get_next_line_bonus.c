#include "get_next_line_bonus.h"
 #define BUFFER_SIZE 42

static int	ft_strlen(const char *str)
{
    if (!str)
        return (0);
    int	i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

static char *ft_strjoin(char const *s1, char const *s2, int d)
{
    char	*str;
    int		i;
    int		j;
    int 	len_two;
    int     len;

    len_two = ft_strlen(s2);
    if (d != -1)
        len_two = d+1;
    str = (char*)malloc(ft_strlen(s1) + len_two + 1);

    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    len = ft_strlen(s1);
    while (i < len)
    {
        // printf("%d %d  ", i, ft_strlen(s1));
        // write(1,"4",1);
        str[j++] = s1[i];
        i++;
    }
    i = 0;
    while (i < len_two)
    {
        // write(1,"5",1);
        str[j++] = s2[i];
        i++;
    }
    str[j] = 0;
    return (str);
}

///////////////////////

static int index(char *str, int d)
{
    int i;

    i = 0;
    while(str[i])
    {
        // write(1,"3",1);
        if (str[i] == d)
            return (i);
        i++;
    }

    return (-1);
}

static void exterminate(char **execution)
{
    if (*execution && execution) // ???
    {
        free (*execution);
        *execution = NULL;
    }
}

static char* move_buf(char *buffer, int check)
{
    char 	*a;
    int 	i;
    int 	j;

    j = 0;
    if (check >= 0)
    {
        i = ft_strlen(buffer) - check; // сколько памяти занимает вторая половина после '\n' -> весь баффер минус число до '\n'
        a = buffer; // переопределяем весь баффер стороннему указателю // ?

        check++;

        buffer = (char *) malloc((i + 1) * sizeof(char)); // ?

        while(a[check])
        {
            // write(1,"2",1);
            buffer[j] = a[check];
            check++;
            j++;
        }

        buffer[j] = '\0';
        exterminate(&a); // чистим весь баффер
    }
    else
    { // колхоз, по другому обыграть
        exterminate(&buffer);
        buffer = (char*)malloc(1);
        buffer[0] = '\0';
    }
    return  buffer;
}

// записывает в result либо до первого '\n', либо сразу до конца баффера
static char *buffer_is_there(char *buffer, char *result, int *check)
{
    char *tmp;

    *check = index(buffer, '\n');
    tmp = result;
    result = ft_strjoin(result, buffer, *check);  // это не закрывает вопрос тем, если '\n' будет не в конце!!!
    if (tmp && *tmp)
        exterminate(&tmp);

    return result;
}

// 1. Делаем без структур
// 2. Делаем с минимум переменных
char *get_next_line(int fd)
{
    static char     *buffer[10243];
    char            *result;
    int				check;
    int				i_read;
    int             i;

    result = NULL;
    check = -1;
    i_read = 1;
    i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if (buffer[fd])
        result = buffer_is_there(buffer[fd], result, &check); // тут сидит либо до 1-го '\n', либо весь баффер
    
    if (check < 0)
    {
        exterminate(&buffer[fd]); // ?
        buffer[fd] = NULL;
        //(char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
        while (i_read > 0 && check < 0) 
        {
            // write(1,"1",1);

            i_read = read(fd, buffer[fd], BUFFER_SIZE);

            if (i_read == -1 || (i == 0 && i_read == 0 && ft_strlen(result) == 0)) // 
            {

                printf("%d", i_read);
                // write(1,&(i_read,40);
                exterminate(&buffer[fd]);
                exterminate(&result);
                return (NULL);
            }

            buffer[fd][i_read] = '\0';
            i++;

            if (buffer[fd])
            {
                result = buffer_is_there(buffer[fd], result, &check);
            //  printf("%d", i_read);
            }
        }
    }
    buffer[fd] = move_buf(buffer[fd], check); // двигаем баффер
    if (buffer[fd][0] == '\0') // колхоз, по другому обыграть
        exterminate(&buffer[fd]);
    return (result);
}

/////////

int main()
{
    printf ("_____________________\n");
    printf ("!!! ПОГНАЛИ НАХУЙ !!!\n");
    printf ("\n");

    int i = 1;
    int fd = open("test.txt", O_RDONLY);
    
      while (i < 4)
    {
        char *m = get_next_line(fd);
        // printf ("_________________________\n");
        printf ("НАШ РЕЗУЛЬТАТ, ПРОГОН №%d: %s", i, m);
        // printf ("\n");
        i++;
        free(m);
    }
	// i = 1;
	//  while (i < 2)
    // {
    //     char *l = get_next_line(9);
    //     // printf ("_________________________\n");
    //     printf ("НАШ РЕЗУЛЬТАТ, ПРОГОН №%d: %s", i, l);
    //     // printf ("\n");
    //     i++;
    //     free(l);
    // }
	// i = 1;
	//  while (i < 2)
    // {
    //     char *d = get_next_line(fd);
    //     // printf ("_________________________\n");
    //     printf ("НАШ РЕЗУЛЬТАТ, ПРОГОН №%d: %s", i, d);
    //     // printf ("\n");
    //     i++;
    //     free(d);
    // }

    return 0;
}

////////////

// static void
// 	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	int	i;

// 	if (!dst || !src)
// 		return (NULL);
// 	if (dst > src)
// 	{
// 		i = (int)len - 1;
// 		while (i >= 0)
// 		{
// 			*(char*)(dst + i) = *(char*)(src + i);
// 			i--;
// 		}
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < (int)len)
// 		{
// 			*(char*)(dst + i) = *(char*)(src + i);
// 			i++;
// 		}
// 	}
// 	return (dst);
// }


// static char *ft_strdup(const char *s1)
// {
//     char *copy;
//     size_t i;

//     i = 0;
//     if (!s1)
//         return (NULL);

//     copy = (char*)malloc( (ft_strlen(s1) + 1) * sizeof(* copy) );
//     if (!copy)
//         return (NULL);

//     while (s1[i])
//     {
//         copy[i] = s1[i];
//         i++;
//     }
//     copy[i] = 0;

//     return copy;
// }


// static char	*ft_strchr(const char *s, int c)
// {
// 	size_t	i;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char) c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)(s + i));
// 	return (0);
// }