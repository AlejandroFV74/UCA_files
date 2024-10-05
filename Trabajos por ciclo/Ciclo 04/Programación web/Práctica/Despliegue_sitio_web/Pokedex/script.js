const pokemons = document.querySelector('.pokemons');
const baseURL = 'https://pokeapi.co/api/v2';

document.getElementById('buscar').addEventListener('click', () => {
  const pokemonID = document.getElementById('pokemon-id').value;
  if (pokemonID) {
    fetchPokemon(pokemonID);
  }
});

function fetchPokemon(id) {
  const resource = `/pokemon/${id}`;
  fetch(`${baseURL}${resource}`)
    .then(res => res.json())
    .then(pokemon => {
      displayPokemon(pokemon);
    })
    .catch(error => {
      pokemons.innerHTML = `<p>Pokémon no encontrado</p>`;
    });
}

function displayPokemon(pokemon) {
  pokemons.innerHTML = `
    <div class="pokemon-info">
      <img src="${pokemon.sprites.front_default}" alt="${pokemon.name}">
      <p>ID: ${pokemon.id}</p>
      <p>Nombre: ${pokemon.name}</p>
      <p>Número en la Pokédex: ${pokemon.id}</p>
    </div>
  `;
}


