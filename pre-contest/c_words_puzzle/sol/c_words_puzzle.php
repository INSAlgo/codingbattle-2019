<?php
$M = "";
$N = 0;
$outDic = array();
$m = "";

fscanf(STDIN, "%s\n", $M);
fscanf(STDIN, "%d\n", $N);

$stringParts = str_split($M);
sort($stringParts);
$MSorted = implode("", $stringParts);

for($i = 0; $i < $N; $i++){
	fscanf(STDIN, "%s\n", $m);
	if($m[0] == $M[0] && $m[strlen($m) - 1] == $M[strlen($M) - 1]){
		$stringParts = str_split($m);
		sort($stringParts);
		$mSorted = implode("", $stringParts);
		if($mSorted == $MSorted)
			$outDic[] = $m;
	}
}

sort($outDic);
foreach ($outDic as $value) {
	echo($value . "\n");
}

?>
