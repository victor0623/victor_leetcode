class Solution {
   public static int[][] flipAndInvertImage(int[][] A) {
        int [][] ReversedImage = new int[A.length][A[0].length];

        for (int i = 0; i < A.length; i++) {
        	for (int j = 0; j < A[i].length; j++) {
        		ReversedImage[i][j] = A[i][A[i].length -1 - j];
        	} 
        }

        int [][] Result = new int[A.length][A[0].length];
        for (int i = 0; i < A.length; i++) {
        	for (int j = 0; j < A[i].length; j++) {
        		if (ReversedImage[i][j] == 0)
        			Result[i][j] = 1;
        		else
        			Result[i][j] = 0;
        	} 
        }

        return Result;
    }
}

public class LeetCode {


   	public static void main(String []args) {
		System.out.println("Original matrix:");

		int[][] A = {{1,1,0}, {1,0,1}, {0,0,0}};
		printMatrix(A);
		printMatrix(flipAndInvertImage(A));

		int [][] B = {{1,1,0,0}, {1,0,0,1}, {0,1,1,1}, {1,0,1,0}};
		printMatrix(B);
		printMatrix(flipAndInvertImage(B));
   }

   public static void printMatrix(int [][] A) {
      for (int i = 0; i < A.length; i++) {
      	for (int j = 0; j < A[i].length; j++)
			System.out.print(A[i][j] + " ");
		System.out.println();
	  } 
   }

   public static int[][] flipAndInvertImage(int[][] A) {
        int [][] ReversedImage = new int[A.length][A[0].length];

        for (int i = 0; i < A.length; i++) {
        	for (int j = 0; j < A[i].length; j++) {
        		ReversedImage[i][j] = A[i][A[i].length -1 - j];
        	} 
        }

        int [][] Result = new int[A.length][A[0].length];
        for (int i = 0; i < A.length; i++) {
        	for (int j = 0; j < A[i].length; j++) {
        		if (ReversedImage[i][j] == 0)
        			Result[i][j] = 1;
        		else
        			Result[i][j] = 0;
        	} 
        }

        return Result;
    }
}