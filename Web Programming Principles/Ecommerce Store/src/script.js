window.onload = function() {
  // clear products from #products div element
  function clear() {
    document.querySelector('#products').innerHTML = '';
  }

  // build card element and return it
  function buildCard() {
    let card = document.createElement('div');
    let image = document.createElement('div');
    let title = document.createElement('div');
    let desc = document.createElement('div');
    let price = document.createElement('div');

    image.appendChild(document.createElement('img'));
    image.classList.add('card-image');
    title.appendChild(document.createElement('p'));
    title.classList.add('title');
    desc.appendChild(document.createElement('p'));
    desc.classList.add('desc');
    price.appendChild(document.createElement('p'));
    price.classList.add('price');

    card.appendChild(image);
    card.appendChild(title);
    card.appendChild(desc);
    card.appendChild(price);
    card.classList.add('card');

    return card;
  }

  // Add card attributes to empty card
  function addToCard(item) {
    let card = '';
    card = buildCard();
    card.querySelector('.card-image img').src = item.image;
    card.querySelector('.card-image img').alt = item.name;
    card.querySelector('.title p').innerHTML = item.name;
    card.querySelector('.desc p').innerHTML = item.desc;
    card.querySelector('.price p').innerHTML = item.price;
    return card;
  }

  // Sort items by category selected
  function sort(category) {
    let dom = document.querySelector('#products');
    for (product in items) {
      if (category == 'All') {
        dom.appendChild(addToCard(items[product]));
      } else if (category == items[product].category) {
        dom.appendChild(addToCard(items[product]));
      }
    }
  }

  // Fill in items at load, default is all items
  sort('All');

  // Category buttons
  let buttons = document.querySelectorAll('#selector button');
  buttons.forEach(e => {
    e.addEventListener('click', b => {
      b.preventDefault();
      clear();
      sort(e.value);
    });
  });
};
