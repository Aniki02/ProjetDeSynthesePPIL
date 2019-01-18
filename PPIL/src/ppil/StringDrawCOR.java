package ppil;

public abstract class StringDrawCOR implements StringDraw{
	protected StringDrawCOR _suivant;
	
	
	public StringDrawCOR(StringDrawCOR suivant) {
		this._suivant = suivant;
	}

	public boolean operation(Fenetre f, String msg) {
		if(operationSpec(f, msg))
			return true;
		else
			if(this._suivant!=null)
				return this._suivant.operation(f, msg);
			else 
				return false;
	}
	
	protected abstract boolean operationSpec(Fenetre f, String msg);
}
