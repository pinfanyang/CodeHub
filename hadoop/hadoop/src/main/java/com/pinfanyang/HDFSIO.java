package com.pinfanyang;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.fs.FileSystem;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IOUtils;
import org.junit.Test;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

public class HDFSIO {

	// 把本地d盘上的banhua.txt文件上传到HDFS根目录
	@Test
	public void putFileToHDFS() throws IOException, InterruptedException, URISyntaxException{
		
		// 1 获取对象
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://hadoop102:9000"), conf , "root");
		
		// 2 获取输入流
		FileInputStream fis = new FileInputStream(new File("C:/Users/杨品凡/Desktop/培训文件/环境搭建/环境包/hadoop-2.7.2.tar.gz"));
		
		// 3 获取输出流
		FSDataOutputStream fos = fs.create(new Path("/hadoop-2.7.2.tar.gz"));
		
		// 4 流的对拷
		IOUtils.copyBytes(fis, fos, conf);
		
		// 5 关闭资源
		IOUtils.closeStream(fos);
		IOUtils.closeStream(fis);
		fs.close();
	}
	
	
	// 从HDFS上下载banhua.txt文件到本地e盘上
	@Test
	public void getFileFromHDFS() throws IOException, InterruptedException, URISyntaxException{
		
		// 1 获取对象
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://hadoop102:9000"), conf , "root");
		
		// 2 获取输入流
		FSDataInputStream fis = fs.open(new Path("/38324.txt"));
		
		// 3 获取输出流
		FileOutputStream fos = new FileOutputStream(new File("d:/14122.txt"));
		
		// 4 流的对拷
		IOUtils.copyBytes(fis, fos, conf);
		
		// 5 关闭资源
		IOUtils.closeStream(fos);
		IOUtils.closeStream(fis);
		fs.close();
	}
	
	// 下载第一块
	@Test
	public void readFileSeek1() throws IOException, InterruptedException, URISyntaxException{
		
		// 1 获取对象
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://hadoop102:9000"), conf , "root");
		
		// 2 获取输入流
		FSDataInputStream fis = fs.open(new Path("/hadoop-2.7.2.tar.gz"));
		
		// 3 获取输出流
		FileOutputStream fos = new FileOutputStream(new File("d:/hadoop-2.7.2.tar.gz.part1"));
		
		// 4 流的对拷（只拷贝128m）
		byte[] buf = new byte[1024];
		for (int i = 0; i < 1024 * 128; i++) {
			fis.read(buf);
			fos.write(buf);
		}
		
		// 5 关闭资源
		IOUtils.closeStream(fos);
		IOUtils.closeStream(fis);
		fs.close();
	}
	
	// 下载第二块
	@SuppressWarnings("resource")
	@Test
	public void readFileSeek2() throws IOException, InterruptedException, URISyntaxException{
		
		// 1 获取对象
		Configuration conf = new Configuration();
		FileSystem fs = FileSystem.get(new URI("hdfs://master:9000"), conf , "root");
		
		// 2 获取输入流
		FSDataInputStream fis = fs.open(new Path("/hadoop-2.7.2.tar.gz"));
		
		// 3 设置指定读取的起点
		fis.seek(1024*1024*128);
		
		// 4 获取输出流
		FileOutputStream fos = new FileOutputStream(new File("e:/hadoop-2.7.2.tar.gz.part2"));
		
		// 5 流的对拷
		IOUtils.copyBytes(fis, fos, conf);
		
		// 6 关闭资源
		IOUtils.closeStream(fos);
		IOUtils.closeStream(fis);
		fs.close();
	}
	
	
	
	
	
	
	
}
