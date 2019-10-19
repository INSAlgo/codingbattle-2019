<?php
fscanf(STDIN, "%d\n", $N);

$input = trim(fgets(STDIN));
$tab = explode(" ", $input);      
foreach($tab as &$number){
    $number = (int)$number;
}

sort($tab);

$a = 0;
$b = 0;
$c = 0;
$mini = -1;
$first = true;
for($i = 0; $i < $N - 2; $i++){
	if($first || $tab[$i + 2] - $tab[$i] < $mini){
		$first = false;
		$a = $tab[$i];
		$b = $tab[$i + 1];
		$c = $tab[$i + 2];
		$mini = $tab[$i + 2] - $tab[$i];
	}
}

echo($a . " " . $b . " " . $c);

?>
