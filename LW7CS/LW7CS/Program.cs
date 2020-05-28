using System;

namespace LW7CS
{
	public class List
	{
		public List()
		{
			size = 0;
			head = null;
		}

		public int getSize()
		{
			return size;
		}

		public void push_back(double data)
		{
			if (head == null)
			{
				head = new Node(data);
			}
			else
			{
				Node current = this.head;
				while (current.NextPointer != null)
				{
					current = current.NextPointer;
				}
				current.NextPointer = new Node(data);
			}

			size++;
		}

		public void erase(int index)
		{
			if (index == 0)
			{
				pop_front();
			}
			else
			{
				Node previous = this.head;
				for (int i = 0; i < index - 1; i++)
				{
					previous = previous.NextPointer;
				}

				Node toDelete = previous.NextPointer;
				previous.NextPointer = toDelete.NextPointer;
				toDelete = null;
				size--;
			}
		}

		public void pop_front()
		{
			Node tmp = head;
			head = head.NextPointer;
			tmp = null;
			size--;
		}

		public double this[int index]
		{
			get
			{
				int counter = 0;
				Node current = this.head;
				while (current != null)
				{
					if (counter == index)
						return current.data;
					current = current.NextPointer;
					counter++;
				}

			}
		}

		private class Node
		{
			public Node NextPointer;
			public double data;
			public Node(double data, Node NextPointer = null)
			{
				this.data = data;
				this.NextPointer = NextPointer;
			}
		}

		private Node head;
		private int size;

	}
	class Program
    {
		public static double searchAvgValue(List list)
		{
			double avgValue = 0;
			for (int i = 0; i < list.getSize(); i++)
			{
				avgValue += list[i];
			}

			avgValue /= list.getSize();
			return avgValue;
		}
		static void Main(string[] args)
        {
			List list = new List();
			list.push_back(5);
			list.push_back(10);
			list.push_back(15);
			list.push_back(20);

			for (int i = 0; i < list.getSize(); i++)
			{
				Console.Write(list[i]);
				Console.Write("\n");
			}

			Console.Write("AvgValue: ");
			Console.WriteLine(searchAvgValue(list));

			for (int i = 0; i < list.getSize(); i += 2)
			{
				list.erase(i);
			}

			Console.WriteLine("List after erasing:");

			for (int i = 0; i < list.getSize(); i++)
			{
				Console.Write(list[i]+" ");
			}
		}
    }
}
