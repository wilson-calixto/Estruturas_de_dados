

package avaliacao;
import java.util.ArrayList;

import javax.swing.JOptionPane;

import avaliacao.Conta;



//import Conta;
public class teste {

	public static void main(String[] args) {
		ArrayList <Conta> contas= new ArrayList<Conta>();
		String opcao;
		
		
		do{
			//opcao = JOptionPane.showInputDialog(null, "Digite a opcao:\n1 - Cadastrar\n2 - Fazerconsulta\n3 - Quitar conta\n4 - Listar contas\n5 - Listar contas de determinado tipo\n - Para sair");
			opcao =JOptionPane.showInputDialog("Escolha um modo:\n 0 finaliza \n 1 cadastra\n 2 - Fazer consulta de acordo com o codigo\n 3 - Fazer consulta de acordo com o mes\n 4 remove uma conta \n 5 listar por tipo \n 6 - Lista as contas pagas \n 7 - Listar contas a pagar ");
			
			if(opcao.equals("8")){
				String contasStr = "";
				for(int i = 0; i < contas.size(); i++){
					contasStr += String.format("%s %f %s %s%n %s", contas.get(i).getTipo(), contas.get(i).getValor(), contas.get(i).getStatus(), contas.get(i).getCodigo(),contas.get(i).getMes());
				}
				JOptionPane.showMessageDialog(null, contasStr);
			}
			
			
			
			if(opcao.charAt(0)=='1')
			{
				String tipo=JOptionPane.showInputDialog("Digite o Tipo de conta");
				String valorStr=JOptionPane.showInputDialog("Digite o valor da conta");
				float valor= Float.parseFloat(valorStr);
				String status=JOptionPane.showInputDialog("A conta esta paga ou a pagar?");
				String codigo=JOptionPane.showInputDialog("Digite o codigo da conta ");
				String mes =JOptionPane.showInputDialog("Digite o mes");
				Conta conta=new Conta(tipo,valor,status,codigo,mes);
				contas.add(conta);
				
			}

			
			

			
			
			
			
			
			
			
			if(opcao.charAt(0)=='2')
			{
				String codigo =JOptionPane.showInputDialog("Digite o codigo da conta");
			
				for(int i=0;i<contas.size();i++)
				{
					
					if(contas.get(i).getCodigo().equals(codigo))
					{
						Float valorFloat=contas.get(i).getValor();
						String valorStr=String.format("%f",valorFloat);
						
						String mensagem = "A conta de codigo "+contas.get(i).getCodigo() +" do tipo "+contas.get(i).getTipo()+" e valor "+valorStr;
						
						if(contas.get(i).getStatus().equals("paga"))
						{
							mensagem+=" esta paga";
							JOptionPane.showMessageDialog(null,mensagem);
						}else{
							mensagem+=" nao esta paga";
							JOptionPane.showMessageDialog(null,mensagem);
							
						}
						
					}
				}
			}
			
			
			if(opcao.charAt(0)=='3')
			{
				String mes =JOptionPane.showInputDialog("Digite o mes");
				float acm=0;
				for(int i=0;i<contas.size();i++)
				{
					
					if(contas.get(i).getMes().equals(mes))
					{
						acm+=contas.get(i).getValor();
						
						
					}
				}

				String mensagem2="Mes da conta "+mes+" valor total "+acm;
				JOptionPane.showMessageDialog(null,mensagem2);

				
			}
			
			
			
			
			
			
			
			
			
				if(opcao.charAt(0)=='4')
				{
					String codigo =JOptionPane.showInputDialog("Digite o codigo da conta");
				
					for(int i=0;i<contas.size();i++)
					{
						
						if(contas.get(i).getCodigo().equals(codigo))
						{
							
							Float valorFloat=contas.get(i).getValor();
							String valorStr=String.format("%f",valorFloat);
							String mensagem = "A conta de codigo "+contas.get(i).getCodigo() +" do tipo "+contas.get(i).getTipo()+" e valor "+valorStr+" foi excluida com sucesso";
							contas.remove(contas.get(i));
							JOptionPane.showMessageDialog(null,mensagem);
							
							
						}
					}
									
				}

				String contasStr="";
				if(opcao.equals("5")){
					String tipo;
					tipo = JOptionPane.showInputDialog(null, "Digite o tipo da conta");
					for(int i = 0; i < contas.size(); i++){
						
					if(contas.get(i).getTipo().equals(tipo) && contas.get(i).getStatus().equals("a pagar")){
							contasStr += String.format("%s %f %s %s%n", contas.get(i).getTipo(), contas.get(i).getValor(), contas.get(i).getStatus(), contas.get(i).getCodigo());
						}
					}
					JOptionPane.showMessageDialog(null, contasStr);
				}
				
				
				if(opcao.charAt(0)=='6')
				{
					
				
					for(int i=0;i<contas.size();i++)
					{
						
						if(contas.get(i).getStatus().equals("paga"))
						{
							Float valorFloat=contas.get(i).getValor();
							String valorStr=String.format("%f",valorFloat);
							
							String mensagem = "A conta de codigo "+contas.get(i).getCodigo() +" do tipo "+contas.get(i).getTipo()+" e valor "+valorStr;
							
								mensagem+=" esta paga";
								JOptionPane.showMessageDialog(null,mensagem);
								
							}
							
						}
					}
				
				
				
				if(opcao.equals("7")){
					for(int i = 0; i < contas.size(); i++){
						if(contas.get(i).getStatus().equals("a pagar"))
							contasStr += String.format("%s %f %s %s%n", contas.get(i).getTipo(), contas.get(i).getValor(), contas.get(i).getStatus(), contas.get(i).getCodigo());
					}
					JOptionPane.showMessageDialog(null, contasStr);
				}
				
				
				
				
	
		}while(opcao.charAt(0)!='0');
		

	}

}


















package avaliacao;



public class Conta {

	private String tipo;
	private float valor;
	private String status,codigo,mes;
	
	
	public String getMes() {
		return mes;
	}


	public Conta(String tipo, float valor, String status, String codigo, String mes) {
		super();
		this.tipo = tipo;
		this.valor = valor;
		this.status = status;
		this.codigo = codigo;
		this.mes = mes;
	}


	public void setMes(String mes) {
		this.mes = mes;
	}


	Conta(){}


	public Conta(String tipo, float valor, String status, String codigo) {
		super();
		this.tipo = tipo;
		this.valor = valor;
		this.status = status;
		this.codigo = codigo;
	}


	public String getCodigo() {
		return codigo;
	}


	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}


	public String getTipo() {
		return tipo;
	}


	public void setTipo(String tipo) {
		this.tipo = tipo;
	}


	public float getValor() {
		return valor;
	}


	public void setValor(float valor) {
		this.valor = valor;
	}


	public String getStatus() {
		return status;
	}


	public void setStatus(String status) {
		this.status = status;
	}
	
	
	
	
}











package eletrodomesticos;

public abstract class Eletrodomesticos {
	String voltagem;
	float preco;
	boolean on_off;
	
	protected  abstract void ligar();

	protected abstract void desligar();
	

}







package eletrodomesticos;

public abstract class EletrodomesticosDaCozinha extends Eletrodomesticos {

	public EletrodomesticosDaCozinha() {
		// TODO Auto-generated constructor stub
	}

	@Override
	protected void ligar() {
		// TODO Auto-generated method stub
		

	}

	@Override
	protected void desligar() {
		// TODO Auto-generated method stub

	}
	protected abstract void dataDeChegada();

	
	

}




package eletrodomesticos;

import javax.swing.JOptionPane;

public class Fogao extends Eletrodomesticos {

	public Fogao() {
		// TODO Auto-generated constructor stub
	}

	@Override
	protected void ligar() {
		// TODO Auto-generated method stub
		on_off=true;
		
		
	}

	@Override
	protected void desligar() {
		// TODO Auto-generated method stub
		on_off=false;
		
		
	}

	void mostra(){
		String m="sou um fogao, bonito e bolado";
		JOptionPane.showMessageDialog(null, m);
		
	}
	
}







package eletrodomesticos;

public class Microondas extends Eletrodomesticos {

	public Microondas() {
		// TODO Auto-generated constructor stub
	}

	@Override
	protected void ligar() {
		// TODO Auto-generated method stub
		on_off=true;
		
	}

	@Override
	protected void desligar() {
		// TODO Auto-generated method stub
		on_off=false;
	}


}






package eletrodomesticos;

public class Geladeira extends EletrodomesticosDaCozinha {

	public Geladeira() {
		// TODO Auto-generated constructor stub
	}

	@Override
	protected void ligar() {
		// TODO Auto-generated method stub
		on_off=true;
		
	}

	@Override
	protected void desligar() {
		// TODO Auto-generated method stub
		on_off=false;
	}
	
	
	@Override
	protected void dataDeChegada() {
		// TODO Auto-generated method stub
		
	}

}













package eletrodomesticos;

import java.util.ArrayList;
import javax.swing.JOptionPane;
public class Principal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 ArrayList <Eletrodomesticos> loja = new ArrayList<Eletrodomesticos>();
		 loja.add(new Geladeira());
		 loja.add(new Microondas());
		 Fogao f =new Fogao();
		 
		 f.mostra();
		 loja.add(f);
	     if (loja.get(2) instanceof Fogao){
	    	 Fogao f2=(Fogao)loja.get(2);
	    	 f2.mostra();
	     }
	}

}




RADIO{
	
	
	
//constantes


private static short final FM =1
private static short final AM =2
}
