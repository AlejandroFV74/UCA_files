/* Ejercicio 1 */
let day = {
    event: ["Waking up", "Eat", "Have web class", "D"],
    check: false,
}

let journal = {
    event: ["Waking up", "Eat", "Have web class", "D"],
    check: false,
    event: ["Waking up", "Drive", "Have web class", "E"],
    check: false,
    event: ["Stand up", "Eat", "Have admin class", "D"],
    check: false,
    event: ["Waking up", "Falling in love", "Have web class", "F"],
    check: false,

}

let journals = [];

const addJournal = (events, accident) => {
    journals.push({ events, accident })
    console.log('day added to the journal');
}

/* Ejercicio 2 */
function transformEveryThing(array, test) {
    let item = [];
    for (let element of array) {
        if (test(element)) {
            item.map(element)
        }
    }
    return item;
}
