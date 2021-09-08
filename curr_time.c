#include <stdio.h>
#include <time.h>
# include <sys/time.h>

// int main ()
// {
// 	time_t rawtime;
// 	struct tm * timeinfo;

// 	time ( &rawtime );
// 	timeinfo = localtime ( &rawtime );
// 	// printf ( "Current local time and date: %s", asctime (timeinfo) );

// 	int day = timeinfo->tm_mday,
// 		mont = timeinfo->tm_mon + 1,
// 		year = timeinfo->tm_year + 1900,
// 		hour = timeinfo->tm_hour,
// 		min = timeinfo->tm_min,
// 		sec = timeinfo->tm_sec;
// 		// ms = timeinfo->
// 		printf("MONTH %d, YEAR %d\n", mont, year);
// 	// printf("[%d %d %d %d:%d:%d]", day, mont, year, hour, min, sec);
// 	return (0);
// }

// int	get_time(void)
// {
// 	struct timeval	current_time;

// 	gettimeofday(&current_time, NULL);
// 	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
// }

// int main()
// {
// 	printf("|%d|\n", get_time());
// }

// # include <unistd.h>

// uint64_t	get_time(void)
// {
// 	struct timeval	current_time;

// 	gettimeofday(&current_time, NULL);
// 	// return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
// 	return (0.001 * 1000);
// }

// double	get_(void)
// {
// 	struct timeval  tv;

// 	gettimeofday(&tv, NULL);
// 	// return  ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
// 	return  (0.001 * 1000);
// }

int main()
{
	struct timeval  tv;

	gettimeofday(&tv, NULL);
	// printf("S|%ld|\t|%d|\n", tv.tv_sec, tv.tv_usec);
	// printf("s |%ld|\t us |%d|\t ms |%ld|\tms exact |%ld|\n", tv.tv_sec, tv.tv_usec,
	// 	tv.tv_sec * 1000,
	// 	((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
	printf("s |%ld|\t", tv.tv_sec);
	printf("us |%d|\t", tv.tv_usec); // 569.843
	printf("ms |%ld|\t", tv.tv_sec * 1000);// 1,630,947,897,000
	printf("ms exact |%ld|\t", ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) );//1630947897569.843
	// printf("ME |%.f|\t", get_());
	// printf("MOUH |%llu|\n", get_time());
}
//1,630,947,739,000
//74.923