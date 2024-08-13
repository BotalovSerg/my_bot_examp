const getHiddenCard = (number_card, hidden = 4) => {
    const result = `${"*".repeat(hidden)}${number_card.slice(12)}`;
    return result;
};

console.log(getHiddenCard('1234567812345678'));