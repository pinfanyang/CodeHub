package 考试程序题;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class 正则表达式 {
	public static void main(String[] args) {
		String content="大叔大婶0555-1111111大师大萨达eqweqwe qeqwe qewqe qeeq eqewqeqweq 是王企鹅翁群无我0555-2315351联系电话";
		String regStr="\\d{4}\\-\\d{7}";
		Pattern pn=Pattern.compile(regStr);	//创建模式对象
		Matcher mr=pn.matcher(content);	//创建匹配器，按照regStr的规则
		while(mr.find()) {
			System.out.println("电话号码为："+mr.group(0));
		}
	}
}


