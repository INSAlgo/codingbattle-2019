<?php
fscanf(STDIN, "%d:%d", $localH, $localM);
fscanf(STDIN, "%d", $ETMinsInEarthMin);
fscanf(STDIN, "%d", $ETMinsInETHour);

$resMins = floor((($localH * $ETMinsInETHour) + $localM) / $ETMinsInEarthMin);
$resHours = floor(($resMins / 60)) % 24;
$resMins = $resMins % 60;
echo($resHours . ":" . $resMins);
?>
