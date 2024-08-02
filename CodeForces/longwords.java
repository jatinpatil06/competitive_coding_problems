import java.util.*;
public class longwords
{
	public static void main(String[] args) {
		int n;
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		String[] A = new String[10000];
		String[] B = new String[100];
		for(int i = 0; i < n; i++)
		{
		    A[i] = sc.next();
		    int l = A[i].length();
		    if(l <= 10)
		        B[i] = A[i];
		    else
		    {
		        B[i] = A[i].charAt(0) + String.valueOf(l -2)+ A[i].charAt(l-1);
		    }
		}
		for(int i = 0; i < n; i++)
		    System.out.println(B[i]);
	}
}
