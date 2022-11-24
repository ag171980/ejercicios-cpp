function cmp(a, b) {
    let result;
    if (a != b) {
        result = (a > b) ? 1 : -1;
    } else {
        result = 0;
    }
    return result;
}

var arr = ["Amumu", "Jayce", "Aatrox", "Pantheon", "Malzahar", "Darius"];
var aux;
for (let i = 0; i < arr.length - 1; i++) {
    for (let j = i + 1; j < arr.length; j++) {
        if (cmp(arr[i], arr[j]) > 0) {
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
}

console.log(arr)