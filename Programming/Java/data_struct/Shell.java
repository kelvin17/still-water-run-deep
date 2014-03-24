
public class Shell {
	
	public static void main(String[] args)
	{
		int[] data = {1,11,6,20,4,2,22,9,0,15,16};
		my_shell(data);
		System.out.println("The sorted list is:");
		for(int i=0;i<data.length;i++)
		{
			System.out.println(data[i]+"  ");
		}	
	}
	//静态方法中调用的方法也只能是静态的。
	public static void my_shell(int[] data)
	{
		int i,h;
		int[] inc = new int[10];
		//计算增量数组
		for(i=0,h=1;h<data.length;i++)
		{
			inc[i] = h;
			h = 3*h+1;
		}
		
		for(i--;i>=0;i--)
		{
			h = inc[i];
			for(int k=1;k<=h;k++)//每次分成h个子数组,k表示组号
			{
				//每个子数组进行插入排序
//				my_insertionsort(data,h,k);
				//每个子数组进行选择排序
//				my_selectsort(data,h,k);
				//每个子数组进行冒泡排序
				my_bubblesort(data,h,k);
			}
		}
	}
	
	public static void my_insertionsort(int[] data,int h,int num)//num 表示组号，h表示增量
	{
		System.out.println("Insertsort selected!");
		for(int i=1;(i*h+num-1)<data.length;i++)
		{
			int tmp = data[i*h + num-1];
			int m;
			for(m = i; m>0 && tmp<data[(m-1)*h+num-1];m--)
			{
				data[m*h+num-1] = data[(m-1)*h+num-1];
			}
			data[m*h+num-1]= tmp;//tmp的最终位置由m决定
		}
	}
	
	public static void my_selectsort(int[] data,int h,int num)
	{
		System.out.println("Selectsort selected!");
		for(int i=0;(i*h+num-1)<data.length;i++)
		{
			int min = i*h + num-1;
			for(int j=i+1;(j*h+num-1)<data.length;j++)
			{
				if(data[min]>data[j*h+num-1])
				{
					min = j*h+num-1;
				}
			}
			
			if(min != i*h+num-1)
			{
				swap(data,min,i*h+num-1);
			}
		}
	}
	
	public static void my_bubblesort(int[] data,int h,int num)
	{
		System.out.println("Bubblesort selected!");
		int i;
		for(i=0;i*h+num-1<data.length;i++);
		int last = i-1;//子数组中的最后一个元素
		
		for(i=0;(i*h+num-1)<data.length;i++)
		{
			for(int j=last;j>i*h+num-1;j--)
			{
				if(data[j] < data[(j-1)*h+num-1])
				{
					swap(data,j,(j-1*h+num-1));
				}
			}
		}
	}
	
	public static void swap(int[] data,int i,int j)
	{
		int tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}
	
	
}
