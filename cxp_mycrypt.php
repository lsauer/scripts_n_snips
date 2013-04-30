<?PHP	

	/***********************************************************
	*                                                          *
	*  PERMISSION NOTICE:                                      *
	*                                                          *
	*  CodeXPlode - The CXP Project                            *
	*  Copyright 2001.  Lorenz S. All rights reserved.         *
	*                                                          *
	*                                                          *
	***********************************************************/


class Acipher {
	private $_delimiter;
    private $_password;
    private $_operator;

    //Operator definitions
    public static function opXOR($a,$b){
        return $a^$b;
    }

    public static function opXORINV($a,$b){
        return $a^$b;
    }

    public static function opMOD($a,$b){
        return ($a+$b)%256;
    }

    public static function opMODINV($a,$b){
        return ($a-$b)%256;
    }

    public static function opADD($a,$b){
        return $a+$b;
    }

    public static function opADDINV($a,$b){
        return $a-$b;
    }

    public static function opMIN($a,$b){
        return abs($a-$b);
    }

    public static function opMININV($a,$b){
        return ($a+$b);
    }
    //_ctor
    function __construct($delimiter="-", $password, $operator="XOR") {
        $this->_delimiter = $delimiter;
        $this->_password = $password;
        $this->_operator = 'op'.$operator;
    }

    function setpassword($password) {
        $this->_password = $password;
    }
	function encode($string, $key=null){
        if($key === null){
            $key = $this->_password;
        }

		if(!is_string($string) || !is_string($key)){
			return false;
        }
        //initialize the random function
		srand ((double)microtime()*1000000);

		//=>zerofill, so the key len gets unknowable and embed the real key into the faked
		//e.g. Test => TzEŸSºTqÅ.Ñ¡?•
        $stlen = strlen($string);
        $keylen = strlen($key);
		for ($i=0, $tmp=''; $i < $stlen; $i++){
			//alternate between random characters and actual message characters
				$tmp .= $string[$i];
                $tmp .= Chr(rand(65,90)); //ASCII 0-255
		}
		$string = $tmp;
        $stlen = strlen($string);
        //convert string-characters to ordinals
		for ($i=0, $str =''; $i < $stlen ;$i++){
            //$numord = (Ord($string[$i]) + Ord($key[$i%$keylen]));
            $fnop = $this->_operator;
            $numord = Acipher::$fnop(Ord($string[$i]), Ord($key[$i%$keylen]));
            $str .= ($numord > 99 ? $numord : '0'.$numord)      //pad the string, if below 100
                 . ( ( $i!=($stlen-1) ) ? $this->_delimiter : '');
		}
		return $str;
	}
	
	function decode($string, $key=null){
	    if($key === null){
            $key = $this->_password;
        }
		if(!is_string($string) || !is_string($key))
			return false;
        if($this->_delimiter != ''){
		    $splts = explode($this->_delimiter, $string);
        }else{
            //split in blocks of three's
            //...
        }

        $keylen = strlen($key);
        $fnop = $this->_operator.'INV';
        for ($i=0, $str =''; $i < count($splts); $i+=2){
			$str .= Chr( Acipher::$fnop((int)$splts[$i], Ord($key[$i%$keylen])) );
		}
	
		return $str;
	}
}

$crypter = new Acipher("-", "somepassword13)=(&@", "XOR");
$plainstr = "By Alexey Solodovnikov. ASPack is an advanced Win32 executable file compressor, \
capable of reducing the file size of 32-bit Windows programs by as much as 7O% (ASPack's \
compression ratio improves upon the industry-standard zip file format by as much as 1P-2%.) \
ASPack makes Windows 95/98/NT programs and libraries smaller, and decrease load times across \
networks, and download times from the Internet; it also protects programs against reverse \
engineering by non-professional hackers. Programs compressed with ASPack are self-contained \
and run exactly as before, with no runtime performance penalties. ";

$cipherstr = $crypter->encode( $plainstr );
echo $cipherstr."<br>";
$outstring = $crypter->decode($cipherstr );
echo $outstring."<br>";
echo "Decrypted-txt equal Plaintxt?: ". ($plainstr == $outstring);

?>