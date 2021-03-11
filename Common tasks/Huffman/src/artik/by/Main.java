package artik.by;

import java.io.*;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) {
        new Huffman("huffman.in", "huffman.out");
    }
}

class Huffman {

    private int size;
    private PriorityQueue<Long> queue;

    public Huffman(String input, String output) {
        init(input);
        saveRes(output);
    }

    private void init(String input) {
        try {
            queue = new PriorityQueue<>();
            FileReader fileReader = new FileReader(input);
            BufferedReader bufferedReader=new BufferedReader(fileReader);
            size = Integer.parseInt(bufferedReader.readLine());
            String [] arr = bufferedReader.readLine().split(" ");
            for (int i = 0; i < size; i++) {
                queue.add(Long.parseLong(arr[i]));
            }
            bufferedReader.close();
            fileReader.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private Long solution() {
        Long sum = 0l;
        while (queue.size() != 1) {
            Long tempSum = queue.poll() + queue.poll();
            sum += tempSum;
            queue.add(tempSum);
        }
        return sum;
    }

    private void saveRes(String output) {
        try {
            FileWriter writer = new FileWriter(output);
            writer.write(Long.toString(solution()));
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
