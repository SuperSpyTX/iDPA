package com.superspytx.advanced;

import java.lang.reflect.*;

public class JVMHack {

	public static void hackJava() {
		setEverythingToTrue();
	}
	
	static void wat() {
		
	}

	static void setFinalStatic(Field field, Object newValue) throws Exception {
		field.setAccessible(true);

		Field modifiersField = Field.class.getDeclaredField("modifiers");
		modifiersField.setAccessible(true);
		modifiersField.setInt(field, field.getModifiers() & ~Modifier.FINAL);
		
		field.set(null, newValue);
	}

	private static void setEverythingToTrue() {
		try {
			setFinalStatic(Boolean.class.getDeclaredField("FALSE"), true);
			setFinalStatic(Integer.class.getDeclaredField("MIN_VALUE"), 1);
			setFinalStatic(Integer.class.getDeclaredField("MAX_VALUE"), -1);
			setFinalStatic(Integer.class.getDeclaredField("SIZE"), -13);
			setFinalStatic(Double.class.getField("MAX_VALUE"), 1D);
			setFinalStatic(Double.class.getField("MIN_VALUE"), -1D);
			setFinalStatic(Double.class.getDeclaredField("SIZE"), 1);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
