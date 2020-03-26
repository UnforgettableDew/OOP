using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1st_lab_cs
{
	public class Line
	{
		private List<char> line = new List<char>();

		public Line(ref string str)
		{
			for (int i = 0; i < str.Length; i++)
				line.Add(str[i]);
			line.Add('\n');
		}

		public void Clear()
		{
			while (line.Count != 0)
				line.RemoveAt(line.Count - 1);
		}

		public ushort CountSpace()
		{
			ushort count = 0;
			for (int i = 0; i < line.Count; i++)
				if (line[i] == ' ')
					count++;
			return count;
		}

		public ushort GetSize()
		{
			ushort size = 0;
			for (int i = 0; i < line.Count; i++)
				size++;
			return size;
		}

		public int GetCount()
		{
			int count = 0;
			for (int i = 0; i < line.Count; i++)
				count++;
			return count - 1;
		}

		public int GetNumberCount()
		{
			int count = 0;
			for (int i = 0; i < line.Count; i++)
				if ((int)line[i] - 48 >= 0 && (int)line[i] - 48 <= 9)
					count++;
			return count;
		}

		public void Print()
		{
			for (int i = 0; i < line.Count; i++)
				Console.Write(line[i]);
		}
	}

	public class Text
	{
		private List<Line> text = new List<Line>();
		public void Init(List<Line> text)
		{
			this.text = new List<Line>(text);
		}

		public void AddLine(Line str)
		{
			text.Add(str);
		}

		public void Clear()
		{
			for (int i = 0; i < text.Count; i++)
				text[i].Clear();
		}

		public void DeleteLine(int number)
		{
			text[number].Clear();
		}

		public void SearchLongLine()
		{
			ushort max = text[0].GetSize();
			ushort index = 0;

			for (int i = 1; i < text.Count; i++)
			{
				if (text[i].GetSize() > max)
				{
					max = text[i].GetSize();
					index = (ushort)i;
				}
			}
			Console.Write("The longest row #");
			Console.Write(index + 1);
			Console.Write(": ");
			text[index].Print();

		}

		public int GetCount()
		{
			int count = 0;
			for (int i = 0; i < text.Count; i++)
				count += text[i].GetCount() - text[i].CountSpace();
			return count;
		}

		public int GetNumberCount()
		{
			int count = 0;
			for (int i = 0; i < text.Count; i++)
				count += text[i].GetNumberCount();
			return count;
		}

		public float GetPercent(Text text)
		{
			float percent = (100 * text.GetNumberCount()) / (float)text.GetCount();
			return percent;
		}

		public void Print()
		{
			for (int i = 0; i < text.Count; i++)
				text[i].Print();
		}
	}

	public class Programm
	{
		static int Main()
		{
			char[,] tmp = new char[255,255];
			int k = 0;
			List<Line> str = new List<Line>();
			Console.Write("Enter text: \n");
			Text text = new Text();
			while (true)
			{
				tmp[k] = Console.ReadLine();
				if (tmp[k,0] == '.')
				{
					break;
				}
				str.Add(tmp[k]);
				k++;
			}
			text.Init(str);


			Console.Write("Search count of all characters #1\n");
			Console.Write("Count of all characters: ");
			Console.Write(text.GetCount());
			Console.Write("\n");

			Console.Write("\nSearch percent of number #2\n");
			Console.Write("Percent of numbers: ");
			Console.Write(text.GetPercent(text));
			Console.Write("%");
			Console.Write("\n");

			Console.Write("\nSearch the longest row #3\n");
			text.SearchLongLine();


			string ch = new string(new char[254]);
			Console.Write("\nAdding the line #4\n");
			Console.Write("Enter the row: ");
			ch = Console.ReadLine();
			Line line = new Line(ref ch);
			text.AddLine(line);
			Console.Write("Text with new row:\n");
			text.Print();

			Console.Write("\nDelete the line #5\n");
			int number;
			Console.Write("\nEnter row's number: ");
			number = Convert.ToInt32(Console.ReadLine());
			text.DeleteLine(number - 1);
			text.Print();

			Console.Write("\nClear text #6\n");
			text.Clear();
			Console.Write("The text is cleared\n");
			text.Print();

			return 0;
		}
	}
}

