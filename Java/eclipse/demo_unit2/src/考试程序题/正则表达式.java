package ���Գ�����;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ������ʽ {
	public static void main(String[] args) {
		String content="�������0555-1111111��ʦ������eqweqwe qeqwe qewqe qeeq eqewqeqweq ���������Ⱥ����0555-2315351��ϵ�绰";
		String regStr="\\d{4}\\-\\d{7}";
		Pattern pn=Pattern.compile(regStr);	//����ģʽ����
		Matcher mr=pn.matcher(content);	//����ƥ����������regStr�Ĺ���
		while(mr.find()) {
			System.out.println("�绰����Ϊ��"+mr.group(0));
		}
	}
}


