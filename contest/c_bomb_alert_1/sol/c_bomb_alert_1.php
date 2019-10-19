<?php

function distance($x1, $y1, $x2, $y2) {
	return sqrt(($x1-$x2)*($x1-$x2)+($y1-$y2)*($y1-$y2));
}

fscanf(STDIN, "%lf %lf", $Xb, $Yb);
fscanf(STDIN, "%d %d", $N, $T);

$vitesseMax = 100;
$coupables = array();
$lastX = 0;
$lastY = 0;

for($i = 0; $i < $N; $i++){
	fscanf(STDIN, "%s", $coupable);
	$criminel = false;
	for($j = 0; $j < $T ; $j++){
		fscanf(STDIN, "%lf %lf", $X, $Y);
		if($j > 0 && distance($lastX, $lastY, $Xb, $Yb) + distance($Xb, $Yb, $X, $Y) <= $vitesseMax)
			$criminel = true;
		$lastX = $X;
		$lastY = $Y;
	}
	if($criminel)
		$coupables[] = $coupable;
}

echo(implode(" ", $coupables));
?>
